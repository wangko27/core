#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QResizeEvent>

#include "Widgets/CStatisticsWidget.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
        ui->setupUi(this);

        ui->horizontalLayout->addWidget(&m_oFileViewWidget);
        ui->horizontalLayout->addWidget(&m_oFileTreeWidget);

        connect(&m_oFileTreeWidget, &Widgets::CFileTreeWidget::signalUpdate, &m_oFileViewWidget, &Widgets::CFileViewWidget::slotUpdate);
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

void MainWindow::ChangeActionActivity(bool bActivity)
{
        ui->actionStatistics->setEnabled(bActivity);
        ui->actionSave_as->setEnabled(bActivity);
}

void MainWindow::on_actionExit_triggered()
{
        QApplication::exit();
}

void MainWindow::on_actionChoose_File_triggered()
{
        std::wstring wsPathToFile = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Metafile (*.emf *.wmf *.svg)")).toStdWString();

        ChangeActionActivity(false);

        if (wsPathToFile.empty())
                return;

        if (m_oFileViewWidget.LoadFile(QString::fromStdWString(wsPathToFile)))
        {
                if (Widgets::FileTypeSvg == m_oFileViewWidget.GetFileType() && m_oFileTreeWidget.SetFile(wsPathToFile, Widgets::FileTypeSvg))
                        ChangeActionActivity(true);
                else if (m_oFileTreeWidget.SetFile(m_oFileViewWidget.GetXmlFilePath().toStdWString(), Widgets::FileTypeMetafile))
                        ChangeActionActivity(true);
        }
        else
        {
                QMessageBox::information(this, "Error", "Couldn't open file");
        }
}


void MainWindow::on_actionStatistics_triggered()
{
        CStatisticsWidget *pStaticsWidget = new CStatisticsWidget;
        pStaticsWidget->SetMainWindow(this);
        pStaticsWidget->SetStatistics(m_oFileTreeWidget.GetStatistics());
        pStaticsWidget->show();
}


void MainWindow::on_actionSave_as_triggered()
{
        QString qsFilter = "*Raster files (*.png)";
        QString qsFilePath = QFileDialog::getSaveFileName(this, "Save file", QDir::currentPath(), "Emf files (*.emf);;Wmf files (*.wmf);;Svg files (*.svg);;Raster files (*.png);;Xml files (*.xml)", &qsFilter);

        if ("Xml files (*.xml)" == qsFilter)
                m_oFileTreeWidget.SaveInXmlFile(qsFilePath.toStdWString());
}

