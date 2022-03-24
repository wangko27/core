#ifndef CFILEVIEWWIDGET_H
#define CFILEVIEWWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

namespace Widgets
{
        typedef enum
        {
                FileTypeUnknown = 0,
                FileTypeMetafile = 1,
                FileTypeSvg = 2
        } FileType;

        class CFileViewWidget : public QWidget
        {
                Q_OBJECT
        public:
                explicit CFileViewWidget(QWidget *parent = nullptr);
                CFileViewWidget(const QString& qsFilePath, QWidget *parent = nullptr);
                virtual ~CFileViewWidget();

                bool LoadFile(const QString& qsFilePath);
                QString GetXmlFilePath() const;
                FileType GetFileType() const;
        private:
                void InitLayout();
                void Clear();

                bool LoadSourceFile(const QString& qsFilePath);
                bool LoadResultingFile(const QString& qsFilePath);

                QString         m_qsRasterFilePath;
                QString         m_qsXmlFilePath;
                QGraphicsScene  m_oSourceFileScene;
                QGraphicsScene  m_oResultingFileScene;

                FileType        m_enFileType;
        };

}


#endif // CFILEVIEWWIDGET_H
