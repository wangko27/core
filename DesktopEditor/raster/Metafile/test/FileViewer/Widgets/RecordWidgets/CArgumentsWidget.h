#ifndef CARGUMENTSWIDGET_H
#define CARGUMENTSWIDGET_H

#include <QWidget>
#include "CSharedWidget.h"

typedef std::vector<std::pair<QString, QString>> ItemArguments;
typedef std::pair<QString, QString>              ItemArgument;

class CArgumentsWidget : public CSharedWidget
{
        Q_OBJECT
public:
        explicit CArgumentsWidget(QWidget *parent = nullptr);
        CArgumentsWidget(const ItemArguments& arArguments, QWidget *parent = nullptr);

        void AddArguments(const ItemArguments& arArguments);
private slots:
        void on_createArgument_clicked();
private:
        void InitWidget();
};

#endif // CARGUMENTSWIDGET_H
