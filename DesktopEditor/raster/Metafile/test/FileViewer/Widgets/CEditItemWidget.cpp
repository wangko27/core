#include "CEditItemWidget.h"
#include "ui_EditItem.h"

#include <QDialogButtonBox>
#include <QResizeEvent>
#include <QPushButton>
#include <QLabel>
#include <QMap>

namespace Widgets
{
        CEditItemWidget::CEditItemWidget(QWidget *parent) :
                QDialog(parent),
                ui(new Ui::CEditItemWidget)
        {
                ui->setupUi(this);

                this->setWindowFlags(Qt::Window  | Qt::WindowCloseButtonHint);
                this->setWindowTitle("Edit");

                ui->MainLayout->setSizeConstraint(QLayout::SetFixedSize);

                QPushButton *pSaveButton     = ui->buttonBox->button(QDialogButtonBox::Save);
                QPushButton *pCloseButton = ui->buttonBox->button(QDialogButtonBox::Close);

                if (NULL != pSaveButton)
                        connect(pSaveButton, &QPushButton::clicked, this, &QDialog::accept);

                if (NULL != pCloseButton)
                        connect(pCloseButton, &QPushButton::clicked, this, &QDialog::reject);
        }

        CEditItemWidget::~CEditItemWidget()
        {
                delete ui;
        }

        void CEditItemWidget::SetItem(CCustomItem *pCustomItem)
        {
                ParseItem(pCustomItem);

                UpdateSize();
        }

        void CEditItemWidget::Update()
        {
                foreach(CCustomItem* pCustomItem, m_oBind.keys())
                {
                        TCCustomItemBind oBind = m_oBind.value(pCustomItem);

                        if (NULL != oBind.pValueEdit)
                                pCustomItem->SetValue(oBind.pValueEdit->toPlainText());

                        if (NULL != oBind.pArgumentsWidget)
                                pCustomItem->SetArguments(oBind.pArgumentsWidget->GetArguments());
                }
        }

        void CEditItemWidget::resizeEvent(QResizeEvent *pResizeEvent)
        {
                unsigned int unHeightButtonBox      = ui->buttonBox->height();
                unsigned int unWorkingPartHeight    = pResizeEvent->size().height();
                unsigned int unWorkingPartWidth     = pResizeEvent->size().width();

                ui->scrollArea->setGeometry(QRect(10, 10, unWorkingPartWidth - 20, unWorkingPartHeight - 20));
                ui->verticalLayoutWidget->setGeometry(QRect(10, 10, unWorkingPartWidth - 40, unWorkingPartHeight - unHeightButtonBox - 10));
        }

        void CEditItemWidget::ParseItem(CCustomItem *pCustomItem)
        {
                if (NULL == pCustomItem)
                        return;

                if (CustomItemTypeRootRecord != pCustomItem->GetType())
                {
                        QPushButton *pDeleteButton = ui->buttonBox->addButton("Delete", QDialogButtonBox::ApplyRole);

                        connect(pDeleteButton, &QPushButton::clicked, this, [this](){emit signalDeleteItem(); this->reject();});
                }

                ParseAttachments(pCustomItem);
        }

        void CEditItemWidget::ParseAttachments(CCustomItem *pCustomItem, unsigned int unLevel)
        {
                if (NULL == pCustomItem)
                        return;

                const unsigned int unCountRow = pCustomItem->rowCount();

                if (0 == unCountRow)
                {
                        QHBoxLayout *pCategoriesLayout = new QHBoxLayout;

                        QLabel *pNameLabel      = new QLabel(pCustomItem->GetName());

                        pCategoriesLayout->addSpacing((unLevel != 0) ? ((unLevel - 1) * 20) : 0);
                        pCategoriesLayout->addWidget(pNameLabel);

                        ParseArguments(pCustomItem, pCategoriesLayout);

                        if (CustomItemTypeRecord != pCustomItem->GetType())
                        {
                                QTextEdit *pValueEdit   = new QTextEdit(pCustomItem->GetValue());

                                QFontMetrics oFontMetrics(pValueEdit->font());
                                pValueEdit->setFixedHeight(oFontMetrics.height() + 10);
                                pValueEdit->setMidLineWidth(30);
                                pValueEdit->setStyleSheet("QTextEdit { vertical-align: middle }");

                                pCategoriesLayout->addWidget(pValueEdit);

                                m_oBind[pCustomItem].pValueEdit = pValueEdit;
                        }

                        pCategoriesLayout->setSizeConstraint(QLayout::SetMinimumSize);

                        ui->DataLayout->addLayout(pCategoriesLayout);
                }
                else
                {
                        if (unLevel != 0)
                        {
                                QLabel *pLabel = new QLabel(pCustomItem->GetName());
                                pLabel->setStyleSheet(QString("QLabel { font-style: italic; margin-left: %1 }").arg((unLevel - 1) * 20));

                                ui->DataLayout->addWidget(pLabel);
                        }
                        else
                                this->setWindowTitle("Edit: " + pCustomItem->GetName());

                        for (unsigned int unNumberRow = 0; unNumberRow < unCountRow; ++unNumberRow)
                                ParseAttachments((CCustomItem*)pCustomItem->child(unNumberRow), unLevel + 1);
                }
        }

        void CEditItemWidget::ParseArguments(CCustomItem *pCustomItem, QHBoxLayout *pLayout)
        {
                if (NULL == pCustomItem || NULL == pLayout || 0 == pCustomItem->GetCountArguments())
                        return;

                CArgumentsWidget *pWidget = new CArgumentsWidget(pCustomItem->GetArguments());

                m_oBind[pCustomItem].pArgumentsWidget = pWidget;

                pLayout->addWidget(pWidget);
        }

        void CEditItemWidget::UpdateSize()
        {
                this->setFixedWidth(ui->DataLayout->sizeHint().width() + 40);
                this->setFixedHeight(ui->MainLayout->sizeHint().height() + ui->buttonBox->height() + 10);
        }
}
