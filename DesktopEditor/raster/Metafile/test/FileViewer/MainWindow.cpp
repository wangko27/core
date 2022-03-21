#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        ui->horizontalLayout->addWidget(&m_oFileViewWidget);
        ui->horizontalLayout->addWidget(&m_oMetafileTreeWidget);
}

MainWindow::~MainWindow()
{
        delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *pResizeEvent)
{
        unsigned int unManubarHeight        = ui->menubar->height();
        unsigned int unWorkingPartHeight    = pResizeEvent->size().height();
        unsigned int unWorkingPartWidth     = pResizeEvent->size().width();

        ui->horizontalLayoutWidget->setGeometry(QRect(0, 0, unWorkingPartWidth, unWorkingPartHeight - unManubarHeight));
}

void MainWindow::on_actionExit_triggered()
{
        QApplication::exit();
}

void MainWindow::on_actionChoose_File_triggered()
{
        std::wstring wsPathToFile = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Metafile (*.emf *.wmf *.svg)")).toStdWString();

        if (wsPathToFile.empty())
                return;

        m_oFileViewWidget.LoadFile(QString::fromStdWString(wsPathToFile));

        m_oMetafileTreeWidget.SetMetafile(wsPathToFile);
}

