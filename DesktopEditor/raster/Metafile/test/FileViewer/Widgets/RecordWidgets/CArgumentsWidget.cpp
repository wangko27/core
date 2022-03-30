#include "CArgumentsWidget.h"

#include <QVBoxLayout>
#include <QPushButton>

#include <QLabel>

#include "CFormCreatorWidget.h"


CArgumentsWidget::CArgumentsWidget(QWidget *parent)
        : CSharedWidget(parent)
{
        InitWidget();
}

CArgumentsWidget::CArgumentsWidget(const ItemArguments &arArguments, QWidget *parent)
        : CSharedWidget(parent)
{
        InitWidget();
        AddArguments(arArguments);
}

void CArgumentsWidget::AddArguments(const ItemArguments &arArguments)
{
        QBoxLayout *pMainLayout = (QBoxLayout*)layout();

        for (const ItemArgument& oArgument : arArguments)
        {
                CFormWidget *pFormWidget = new CFormWidget(oArgument.first, oArgument.second);

                m_arFormWidgets.push_back(pFormWidget);

                pMainLayout->insertWidget(pMainLayout->count() - 1, pFormWidget);
        }
}

ItemArguments CArgumentsWidget::GetArguments()
{
        ItemArguments arArguments;

        for (const CFormWidget* pWidget : m_arFormWidgets)
                arArguments.push_back(ItemArgument(pWidget->GetName(), pWidget->GetTextEditWidget()->toPlainText()));

        return arArguments;
}

void CArgumentsWidget::on_createArgument_clicked()
{
        CFormCreatorWidget oFormCreatorWidget;

        if (QDialog::Accepted == oFormCreatorWidget.exec())
        {
                CFormWidget *pFormWidget = new CFormWidget(oFormCreatorWidget.GetName(), oFormCreatorWidget.GetValue());

                m_arWidgets.push_back(pFormWidget);

                QBoxLayout *pMainLayout = (QBoxLayout*)layout();
                pMainLayout->insertWidget(pMainLayout->count() - 1, pFormWidget);
        }
}

void CArgumentsWidget::InitWidget()
{
        QVBoxLayout *pLayout = new QVBoxLayout;

        pLayout->setSizeConstraint(QLayout::SetFixedSize);

//        QPushButton *pButtonAddPoint = new QPushButton("+");

//        connect(pButtonAddPoint, &QPushButton::clicked, this, &CArgumentsWidget::on_createArgument_clicked);

        pLayout->addWidget(new QLabel("Arguments:"));
//        pLayout->addWidget(pButtonAddPoint);

        setLayout(pLayout);
}
