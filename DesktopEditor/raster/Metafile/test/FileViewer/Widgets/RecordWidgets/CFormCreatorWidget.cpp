#include "CFormCreatorWidget.h"
#include "ui_FormCreator.h"

#include <QPushButton>

CFormCreatorWidget::CFormCreatorWidget(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CFormCreatorWidget)
{
        ui->setupUi(this);

        connect(ui->LineEditName, &QLineEdit::textEdited, this, &CFormCreatorWidget::CheckName);

        QPushButton *pOkButton     = ui->buttonBox->button(QDialogButtonBox::Ok);
        QPushButton *pCancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);

        if (NULL != pOkButton)
        {
                pOkButton->setEnabled(false);
                connect(pOkButton, &QPushButton::clicked, this, &QDialog::accept);
        }

        if (NULL != pCancelButton)
                connect(pCancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

CFormCreatorWidget::~CFormCreatorWidget()
{
        delete ui;
}

QString CFormCreatorWidget::GetName() const
{
        return ui->LineEditName->text();
}

QString CFormCreatorWidget::GetValue() const
{
        return ui->LineEditValue->text();
}

void CFormCreatorWidget::CheckName(const QString &qsValue)
{
        QPushButton *pOkButton = ui->buttonBox->button(QDialogButtonBox::Ok);

        if (NULL == pOkButton)
                return;

        if (!qsValue.isEmpty())
                pOkButton->setEnabled(true);
        else
                pOkButton->setEnabled(false);

}
