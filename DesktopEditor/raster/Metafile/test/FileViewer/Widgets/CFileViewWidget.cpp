#include "CFileViewWidget.h"

#include <QBoxLayout>

//Для отрисовки Svg средствами Qt
#include <QGraphicsSvgItem>
#include <QSvgRenderer>

//Для отрисовки Emf/Wmf средствами GDI+
#include <Windows.h>
using namespace std; // устраняет ошибки с min, max при компиляции (связано с подключением gdiplus)
#include <gdiplus.h>
#pragma comment (lib,"gdiplus.lib")
#include <QPixmap>
Q_GUI_EXPORT QPixmap qt_pixmapFromWinHBITMAP(HBITMAP bitmap, int hbitmapFormat=0);

//Для ковнертации файла в растровое изображение
#include "../../../../graphics/pro/Fonts.h"
#include "../../../../graphics/pro/Graphics.h"
#include "../../../../fontengine/ApplicationFontsWorker.h"

#include "../../../../raster/BgraFrame.h"
#include "../../../../common/Directory.h"

namespace Widgets
{
        CFileViewWidget::CFileViewWidget(QWidget *parent) : QWidget(parent), m_enFileType(FileTypeUnknown)
        {
                InitLayout();
        }

        CFileViewWidget::CFileViewWidget(const QString &qsFilePath, QWidget *parent) : QWidget(parent)
        {
                InitLayout();
                LoadFile(qsFilePath);
        }

        CFileViewWidget::~CFileViewWidget()
        {
                Clear();
        };

        bool CFileViewWidget::LoadFile(const QString &qsFilePath)
        {
                if (qsFilePath.isEmpty())
                        return false;

                Clear();

                bool bLoadSourceFile = LoadSourceFile(qsFilePath);
                bool bResultingFile  = LoadResultingFile(qsFilePath);

                return bLoadSourceFile * bResultingFile;
        }

        QString CFileViewWidget::GetXmlFilePath() const
        {
                return m_qsXmlFilePath;
        }

        FileType CFileViewWidget::GetFileType() const
        {
                return m_enFileType;
        }

        void CFileViewWidget::InitLayout()
        {
                QVBoxLayout *pMainLayout = new QVBoxLayout;

                setLayout(pMainLayout);

                QGraphicsView *pSourceFileView = new QGraphicsView;
                pSourceFileView->setScene(&m_oSourceFileScene);

                QGraphicsView *pResultingFileView = new QGraphicsView;
                pResultingFileView->setScene(&m_oResultingFileScene);

                pMainLayout->addWidget(pSourceFileView);
                pMainLayout->setStretch(0, 1);
                pMainLayout->addWidget(pResultingFileView);
                pMainLayout->setStretch(1, 1);
        }

        void CFileViewWidget::Clear()
        {
                NSFile::CFileBinary::Remove(m_qsRasterFilePath.toStdWString());
                NSFile::CFileBinary::Remove(m_qsXmlFilePath.toStdWString());

                m_oSourceFileScene.clear();
                m_oResultingFileScene.clear();

                m_qsXmlFilePath.clear();
        }

        bool CFileViewWidget::LoadSourceFile(const QString &qsFilePath)
        {
                m_enFileType = FileTypeUnknown;

                QGraphicsSvgItem *pGraphicsSvgItem = new QGraphicsSvgItem(qsFilePath);

                if (pGraphicsSvgItem->renderer()->isValid()) //Это Svg
                {
                        m_enFileType = FileTypeSvg;
                        m_oSourceFileScene.addItem(pGraphicsSvgItem);
                        return true;
                }

                delete pGraphicsSvgItem;

                Gdiplus::GdiplusStartupInput gdiplusStartupInput;
                ULONG_PTR gdiplusToken;

                GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

                Gdiplus::Bitmap *pBitmap = Gdiplus::Bitmap::FromFile(qsFilePath.toStdWString().c_str());

                HBITMAP handleToSliceRet = NULL;
                pBitmap->GetHBITMAP(Gdiplus::Color::Transparent, &handleToSliceRet);

                if (NULL == handleToSliceRet)
                {
                        delete pBitmap;
                        return false;
                }
                else // Это Emf/Wmf
                {
                        m_enFileType = FileTypeMetafile;

                        QPixmap oPixmap = qt_pixmapFromWinHBITMAP(handleToSliceRet);
                        m_oSourceFileScene.addPixmap(oPixmap);

                        return true;
                }

                return false;
        }

        bool CFileViewWidget::LoadResultingFile(const QString &qsFilePath)
        {
                if (FileTypeUnknown == m_enFileType)
                        return false;

                CApplicationFontsWorker oWorker;
                oWorker.m_sDirectory = NSFile::GetProcessDirectory() + L"/fonts_cache";
                oWorker.m_bIsNeedThumbnails = false;

                if (!NSDirectory::Exists(oWorker.m_sDirectory))
                        NSDirectory::CreateDirectory(oWorker.m_sDirectory);

                NSFonts::IApplicationFonts* pFonts = oWorker.Check();

                MetaFile::IMetaFile* pMetafile = MetaFile::Create(pFonts);
                if (!pMetafile->LoadFromFile(qsFilePath.toStdWString().c_str()))
                        return false;

                m_qsRasterFilePath    = QString::fromStdWString(NSFile::GetProcessDirectory() + L"/Temp.png");

                if (FileTypeSvg == m_enFileType)
                {
                        pMetafile->ConvertToRaster(m_qsRasterFilePath.toStdWString().c_str(), 4, 1000);
                }
                else
                {
                        m_qsXmlFilePath = QString::fromStdWString(NSFile::GetProcessDirectory() + L"/Temp.xml");
                        pMetafile->ConvertToXmlAndRaster(m_qsXmlFilePath.toStdWString().c_str(), m_qsRasterFilePath.toStdWString().c_str(), 4, 1000);
                }

                pMetafile->Release();
                pFonts->Release();

                QImage oImage(m_qsRasterFilePath);

                m_oResultingFileScene.addPixmap(QPixmap::fromImage(QImage(oImage)));

                return true;
        }
}
