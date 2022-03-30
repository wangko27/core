#ifndef CEDITITEMWIDGET_H
#define CEDITITEMWIDGET_H

#include <QDialog>
#include "Common/CCustomItem.h"
#include <QHBoxLayout>
#include <QTextEdit>

#include "RecordWidgets/CArgumentsWidget.h"

namespace Ui {
        class CEditItemWidget;
}

namespace Widgets
{
        struct TCCustomItemBind
        {
                QTextEdit* pValueEdit;
                CArgumentsWidget *pArgumentsWidget;
        };

        class CEditItemWidget : public QDialog
        {
                Q_OBJECT

            public:
                explicit CEditItemWidget(QWidget *parent = nullptr);
                ~CEditItemWidget();

                void SetItem(CCustomItem* pCustomItem);
                void Update();

            signals:
                void signalDeleteItem();

            protected:
                void resizeEvent(QResizeEvent *pResizeEvent) override;

            private:
                void ParseItem(CCustomItem* pCustomItem);
                void ParseAttachments(CCustomItem* pCustomItem, unsigned int unLevel = 0);
                void ParseArguments(CCustomItem* pCustomItem, QHBoxLayout* pLayout);

                Ui::CEditItemWidget *ui;

                QMap<CCustomItem*, TCCustomItemBind> m_oBind;

                void UpdateSize();
        };
}


#endif // CEDITITEMWIDGET_H
