#ifndef CFILEVIEWWIDGET_H
#define CFILEVIEWWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

namespace FileView
{
        class CFileViewWidget : public QWidget
        {
                Q_OBJECT
        public:
                explicit CFileViewWidget(QWidget *parent = nullptr);
                CFileViewWidget(const QString& qsFilePath, QWidget *parent = nullptr);
                virtual ~CFileViewWidget();

                bool LoadFile(const QString& qsFilePath);
        private:
                void InitLayout();
                void Clear();

                bool LoadSourceFile(const QString& qsFilePath);
                bool LoadResultingFile(const QString& qsFilePath);

                QString         m_qsFilePath;
                QGraphicsScene  m_oSourceFileScene;
                QGraphicsScene  m_oResultingFileScene;

//                QGraphicsView   m_oSourceFileView;
//                QGraphicsView   m_oResultingFileView;
        };

}


#endif // CFILEVIEWWIDGET_H
