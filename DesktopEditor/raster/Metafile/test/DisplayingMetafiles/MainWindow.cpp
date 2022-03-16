#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QResizeEvent>

#include <QGraphicsSvgItem>

#include "Widgets/CFileViewWidget.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        FileView::CFileViewWidget *pWidget = new FileView::CFileViewWidget("Path");
        ui->verticalLayout->addWidget(pWidget);
}

void MainWindow::resizeEvent(QResizeEvent *pResizeEvent)
{
        unsigned int unManubarHeight        = ui->menubar->height();
        unsigned int unWorkingPartHeight    = pResizeEvent->size().height();
        unsigned int unWorkingPartWidth     = pResizeEvent->size().width();

        ui->horizontalLayoutWidget->setGeometry(QRect(0, 0, unWorkingPartWidth, unWorkingPartHeight - unManubarHeight));
}

MainWindow::~MainWindow()
{
        delete ui;
}

