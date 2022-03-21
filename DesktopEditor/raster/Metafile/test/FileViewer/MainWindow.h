#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Widgets/CFileViewWidget.h"
#include "Widgets/CMetafileTreeWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

private slots:
        void on_actionExit_triggered();

        void on_actionChoose_File_triggered();

protected:
        void resizeEvent(QResizeEvent *pResizeEvent) override;

private:
        Ui::MainWindow *ui;
        FileView::CFileViewWidget m_oFileViewWidget;
        CMetafileTreeWidget       m_oMetafileTreeWidget;
};
#endif // MAINWINDOW_H
