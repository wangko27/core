#ifndef CFORMCREATORWIDGET_H
#define CFORMCREATORWIDGET_H

#include <QDialog>

namespace Ui {
        class CFormCreatorWidget;
}

class CFormCreatorWidget : public QDialog
{
        Q_OBJECT

public:
        explicit CFormCreatorWidget(QWidget *parent = nullptr);
        ~CFormCreatorWidget();

        QString GetName() const;
        QString GetValue() const;
private slots:
        void CheckName(const QString & qsValue);
private:
        Ui::CFormCreatorWidget *ui;
};

#endif // CFORMCREATORWIDGET_H
