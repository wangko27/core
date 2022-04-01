#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Widgets/CFileViewWidget.h"
#include "Widgets/CFileTreeWidget.h"

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

        void on_actionStatistics_triggered();

        void on_actionSave_as_triggered();

protected:
        void resizeEvent(QResizeEvent *pResizeEvent) override;

private:
        void ChangeActionActivity(bool bActivity);

        Ui::MainWindow *ui;
        Widgets::CFileViewWidget m_oFileViewWidget;
        Widgets::CFileTreeWidget m_oFileTreeWidget;
};
#endif // MAINWINDOW_H
