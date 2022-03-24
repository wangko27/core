#ifndef CMETAFILETREEWIDGET_H
#define CMETAFILETREEWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

#include "Common/CTextEditDelegate.h"
#include "Common/CFileTreeView.h"

namespace Widgets
{
        class CFileTreeWidget : public QWidget
        {
                Q_OBJECT
            public:
                CFileTreeWidget(QWidget *parent = NULL);
                ~CFileTreeWidget();

                void Clear();

                //Методы QTreeView
                void setItemDelegate(CTextEditDelegate *pTextEditDelegate);
                void expandAll();
                void collapseAll();
                QAbstractItemModel* model();
                void setFrameShadow(QFrame::Shadow enShadow);
                void setSelectionBehavior(QAbstractItemView::SelectionBehavior unBehavior);
                void setAutoExpandDelay(int nDelay);
                void setRootIsDecorated(bool bShow);
                void setAnimated(bool bEnable);
                QHeaderView* header();

                //Методы CFileTreeView
                bool SetFile(const std::wstring& wsXmlFilePath);
                bool IsClearTree();
                void SetMode(bool bLightMode);
                void ClearTree();
                QMap<QString, unsigned int> GetStatistics();

                bool SaveInXmlFile(const std::wstring& wsSaveFilePath);

                void EditItem(CCustomItem* pStandardItem);

            protected:
                virtual void mouseReleaseEvent(QMouseEvent* event) override;

            private slots:
                void slotFindNext();
                void slotFindPrev();
                void slotRBClickedOnMetafileTree(QPoint oPoint);
                void slotDeleteItem(CCustomItem *pDeletedItem);

            private:
                void InsertRecord(CCustomItem *pParentItem, unsigned int unRow, bool bAfterRecord = true);

                QTextEdit *m_pFindText;
                QPushButton *m_pFindNextButton;
                QPushButton *m_pFindPrevButton;

                CFileTreeView *m_pFileTreeView;
                int m_nIndexSelectedItem;
                QStandardItem *m_pSelectedItem;
        };
}

#endif // CMETAFILETREEWIDGET_H
