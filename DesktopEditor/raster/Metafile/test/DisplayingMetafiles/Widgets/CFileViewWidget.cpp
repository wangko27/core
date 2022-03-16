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

namespace FileView
{
        CFileViewWidget::CFileViewWidget(QWidget *parent) : QWidget(parent)
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
                NSFile::CFileBinary::Remove(L"Temp.png");
        };

        bool CFileViewWidget::LoadFile(const QString &qsFilePath)
        {
                if (qsFilePath.isEmpty())
                        return false;

                bool bLoadSourceFile = LoadSourceFile(qsFilePath);
                bool bResultingFile  = LoadResultingFile(qsFilePath);

                return bLoadSourceFile * bResultingFile;
        }

        void CFileViewWidget::InitLayout()
        {
                QVBoxLayout *pMainLayout = new QVBoxLayout;

                setLayout(pMainLayout);

                pMainLayout->addWidget(&m_oSourceFileView);
                pMainLayout->setStretch(0, 1);
                pMainLayout->addWidget(&m_oResultingFileView);
                pMainLayout->setStretch(1, 1);
        }

        bool CFileViewWidget::LoadSourceFile(const QString &qsFilePath)
        {
                QGraphicsSvgItem *pGraphicsSvgItem = new QGraphicsSvgItem(qsFilePath);

                if (pGraphicsSvgItem->renderer()->isValid()) //Это Svg
                {
                        QGraphicsScene *pGraphicsScene = new QGraphicsScene;

                        pGraphicsScene->addItem(pGraphicsSvgItem);

                        m_oSourceFileView.setScene(pGraphicsScene);

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
                        QPixmap oPixmap = qt_pixmapFromWinHBITMAP(handleToSliceRet);

                        QGraphicsScene *pScene = new QGraphicsScene;

                        pScene->addPixmap(oPixmap);

                        m_oSourceFileView.setScene(pScene);

                        return true;
                }

                return false;
        }

        bool CFileViewWidget::LoadResultingFile(const QString &qsFilePath)
        {
                CApplicationFontsWorker oWorker;
                oWorker.m_sDirectory = NSFile::GetProcessDirectory() + L"/fonts_cache";
                oWorker.m_bIsNeedThumbnails = false;

                if (!NSDirectory::Exists(oWorker.m_sDirectory))
                        NSDirectory::CreateDirectory(oWorker.m_sDirectory);

                NSFonts::IApplicationFonts* pFonts = oWorker.Check();

                MetaFile::IMetaFile* pMetafile = MetaFile::Create(pFonts);
                if (!pMetafile->LoadFromFile(qsFilePath.toStdWString().c_str()))
                        return false;

                std::wstring wsPathToRasterFile = NSFile::GetProcessDirectory() + L"/Temp.png";

                pMetafile->ConvertToRaster(wsPathToRasterFile.c_str(), 4, 1000);

                pMetafile->Release();
                pFonts->Release();

                QImage oImage(QString::fromStdWString(wsPathToRasterFile));
                QGraphicsScene *pGraphicsScene = new QGraphicsScene;
                pGraphicsScene->addPixmap(QPixmap::fromImage(QImage(oImage)));
                m_oResultingFileView.setScene(pGraphicsScene);

                return false;
        }
}
