#include "CEditItemWidget.h"
#include "ui_EditItem.h"

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>

#include <MainWindow.h>

CEditItemWidget::CEditItemWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CEditItemWidget),
        m_pMainWindow(NULL),
        m_pStandardItem(NULL),
        m_pContentLayout(NULL),
        m_pButtonsLayout(NULL)
{
        this->setWindowFlags(Qt::Window  | Qt::WindowCloseButtonHint);
        this->setWindowTitle("Edit");

        QVBoxLayout *pMainLayout    = new QVBoxLayout(this);
        QScrollArea *pScrollArea    = new QScrollArea();
        QWidget *pMainWidget        = new QWidget();
        m_pContentLayout            = new QVBoxLayout(pMainWidget);

        pMainLayout->addWidget(pScrollArea);
        pScrollArea->setWidget(pMainWidget);

        m_pButtonsLayout     = new QHBoxLayout;

        QPushButton *pSaveButton    = new QPushButton("Save");
        QPushButton *pCancelButton  = new QPushButton("Cancel");

        connect(pSaveButton,    &QPushButton::clicked, this, &CEditItemWidget::slotSaveButtonCliked);
        connect(pCancelButton,  &QPushButton::clicked, this, &CEditItemWidget::slotCancelButtonClicked);

        m_pButtonsLayout->addWidget(pSaveButton);
        m_pButtonsLayout->addWidget(pCancelButton);
        m_pButtonsLayout->setStretch(0, 1);

        pMainLayout->addLayout(m_pButtonsLayout);

        m_pContentLayout->setSizeConstraint(QLayout::SetFixedSize);

        ui->setupUi(this);
}

CEditItemWidget::~CEditItemWidget()
{
        delete ui;
}

void CEditItemWidget::SetMainWindow(MainWindow *pMainWidget)
{
        m_pMainWindow = pMainWidget;

        if(NULL != pMainWidget)
                pMainWidget->setEnabled(false);
}

void CEditItemWidget::SetItem(CCustomItem *pCustomItem)
{
        m_pStandardItem = pCustomItem;
        ParsingItem();
}

void CEditItemWidget::slotSaveButtonCliked()
{
        for (CCustomItem* pCustomItem : m_oBind)
        {
                const QTextEdit* pTextEdit = m_oBind.key(pCustomItem);

                unsigned int unFirstQuotationMark, unLastSlash;

                const QString qsStandardItemValue = pCustomItem->data(0).toString();

                unFirstQuotationMark = qsStandardItemValue.indexOf('>');
                unLastSlash = qsStandardItemValue.lastIndexOf('/');

                const QString qsName = qsStandardItemValue.mid(1, ((unLastSlash > unFirstQuotationMark) ? (unFirstQuotationMark) : (unLastSlash)) - 1);
                const QString qsValue = pTextEdit->toPlainText();

                if (qsValue.isEmpty())
                        pCustomItem->setText(QString("<%1/>").arg(qsName));
                else
                        pCustomItem->setText(QString("<%1>%2</%1>").arg(qsName).arg(qsValue));
        }

//        if (!m_oBind.empty() && NULL != m_pMainWindow)
//        {
//                if (m_pMainWindow->SaveInXmlFile(L"Temp.xml") &&
//                    m_pMainWindow->ConvertToEmf(L"Temp.xml"))
//                        m_pMainWindow->DisplayingFile(L"TempFile.emf", false);
//        }

        slotCancelButtonClicked();
}

void CEditItemWidget::slotCancelButtonClicked()
{
        if (NULL != m_pMainWindow)
                m_pMainWindow->setEnabled(true);

        this->close();
}

void CEditItemWidget::slotDeleteButtonClicked()
{
        DeleteItem(m_pStandardItem);
}

void CEditItemWidget::ParsingItem()
{
        if (NULL == m_pStandardItem)
                return;

        if (CustomItemTypeRootRecord != m_pStandardItem->GetType())
        {
                QPushButton *pDeleteButton = new QPushButton("Delete");

                connect(pDeleteButton, &QPushButton::clicked, this, &CEditItemWidget::slotDeleteButtonClicked);

                m_pButtonsLayout->addWidget(pDeleteButton);
        }

        ParsingAttachments(m_pStandardItem);
}

void CEditItemWidget::ParsingAttachments(CCustomItem *pCustomItem, unsigned int unLevel)
{
        if (NULL == pCustomItem)
                return;

        const unsigned int unCountRow = pCustomItem->rowCount();

        if (unCountRow == 0)
        {
                QHBoxLayout *pLayout = new QHBoxLayout;

                QLabel *pNameLabel = new QLabel(pCustomItem->GetName());
                QTextEdit *pValueEdit = new QTextEdit(pCustomItem->GetValue());

                pNameLabel->setStyleSheet(QString("QLabel { margin-left: %1 }").arg((unLevel - 1) * 20));

                QFontMetrics oFontMetrics(pValueEdit->font());
                pValueEdit->setFixedHeight(oFontMetrics.height() + 10);
                pValueEdit->setStyleSheet("QTextEdit { vertical-align: middle }");
                pLayout->addWidget(pNameLabel);
                pLayout->addWidget(pValueEdit);

                m_oBind.insert(pValueEdit, pCustomItem);

                m_pContentLayout->addLayout(pLayout);
        }
        else
        {
                if (unLevel != 0)
                {
                        QLabel *pLabel = new QLabel(pCustomItem->GetName());
                        pLabel->setStyleSheet(QString("QLabel { font-style: italic; margin-left: %1 }").arg((unLevel - 1) * 20));

                        m_pContentLayout->addWidget(pLabel);
                }
                else
                        this->setWindowTitle("Edit: " + pCustomItem->GetName());

                for (unsigned int unNumberRow = 0; unNumberRow < unCountRow; ++unNumberRow)
                        ParsingAttachments((CCustomItem*)pCustomItem->child(unNumberRow), unLevel + 1);
        }
}

void CEditItemWidget::closeEvent(QCloseEvent *event)
{
        slotCancelButtonClicked();
}

void CEditItemWidget::DeleteItem(CCustomItem *pCustomItem)
{
        QStandardItem *pParent = pCustomItem->parent();

        if (NULL == pParent)
                return;

        emit signalDeleteItem(pCustomItem);

        pParent->removeRow(pCustomItem->index().row());

//        if (NULL != m_pMainWindow)
//        {
//                if (m_pMainWindow->SaveInXmlFile(L"Temp.xml") &&
//                    m_pMainWindow->ConvertToEmf(L"Temp.xml"))
//                        m_pMainWindow->DisplayingFile(L"TempFile.emf", false);
//        }

        slotCancelButtonClicked();
}
