#ifndef CEDITITEMWIDGET_H
#define CEDITITEMWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QBoxLayout>

#include "CCustomItem.h"
#include "MainWindow.h"

namespace Ui {
        class CEditItemWidget;
}

class CEditItemWidget : public QWidget
{
        Q_OBJECT
    public:
        explicit CEditItemWidget(QWidget *parent = nullptr);
        ~CEditItemWidget();

        void SetMainWindow(MainWindow *pMainWindow);
        void SetItem(CCustomItem *pStandardItem);

    private slots:
        void slotSaveButtonCliked();
        void slotCancelButtonClicked();

        void slotDeleteButtonClicked();

    signals:
        void signalDeleteItem(CCustomItem *pDeletedItem);

    private:
        void ParsingItem();
        void ParsingAttachments(CCustomItem* pStandardItem, unsigned int unLevel = 0);

        void closeEvent(QCloseEvent *event) override;
        void DeleteItem(CCustomItem *pCustomItem);

        Ui::CEditItemWidget *ui;
        MainWindow      *m_pMainWindow;
        CCustomItem     *m_pStandardItem;
        QBoxLayout      *m_pContentLayout;
        QBoxLayout      *m_pButtonsLayout;

        QMap<QTextEdit*, CCustomItem*> m_oBind;
};

#endif // CEDITITEMWIDGET_H
