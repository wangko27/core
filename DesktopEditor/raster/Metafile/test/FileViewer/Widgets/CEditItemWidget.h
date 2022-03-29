#ifndef CEDITITEMWIDGET_H
#define CEDITITEMWIDGET_H

#include <QDialog>
#include "Common/CCustomItem.h"
#include <QHBoxLayout>
#include <QTextEdit>

namespace Ui {
        class CEditItemWidget;
}

namespace Widgets
{
        class CEditItemWidget : public QDialog
        {
                Q_OBJECT

            public:
                explicit CEditItemWidget(QWidget *parent = nullptr);
                ~CEditItemWidget();

                void SetItem(CCustomItem* pCustomItem);

            protected:
                void resizeEvent(QResizeEvent *pResizeEvent) override;

            private:
                void ParseItem(CCustomItem* pCustomItem);
                void ParseAttachments(CCustomItem* pCustomItem, unsigned int unLevel = 0);
                void ParseArguments(CCustomItem* pCustomItem, QHBoxLayout* pLayout);

                Ui::CEditItemWidget *ui;
                QMap<QTextEdit*, CCustomItem*> m_oBind;

                void UpdateSize();
        };
}


#endif // CEDITITEMWIDGET_H
