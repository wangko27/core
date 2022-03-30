#ifndef CMETAFILETREEWIDGET_H
#define CMETAFILETREEWIDGET_H

#include <QFrame>
#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

#include "Common/CTextEditDelegate.h"
#include "Common/CFileTreeView.h"
#include "CFileViewWidget.h"

namespace Widgets
{
        typedef QMap<QString, unsigned int> Statistics;
        class CFileTreeWidget : public QWidget
        {
                Q_OBJECT
            public:
                CFileTreeWidget(QWidget *parent = NULL);
                ~CFileTreeWidget();

                void Clear();

                //Методы QTreeView
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
                bool SetFile(const std::wstring& wsXmlFilePath, FileType enType);
                bool IsClearTree();
                void SetMode(bool bLightMode);
                void ClearTree();
                Statistics GetStatistics();
                void ProcessNode(const CCustomItem *pCustomItem, Statistics& mStatistics);

                bool SaveInXmlFile(const std::wstring& wsSaveFilePath);

                void EditItem(CCustomItem* pStandardItem);

            protected:
                virtual void mouseReleaseEvent(QMouseEvent* event) override;

            signals:
                void signalUpdate();

            private slots:
                void slotFindNext();
                void slotFindPrev();
                void slotRBClickedOnMetafileTree(QPoint oPoint);
                void slotDeleteItem();

            private:
                void InsertRecord(CCustomItem *pParentItem, unsigned int unRow, bool bAfterRecord = true);

                bool FindLower(CCustomItem* pCustomItem, QString qsFindValue);
                bool FindUpperLower(CCustomItem* pCustomItem, QString qsFindValue);
                bool FindUpperUpper(CCustomItem* pCustomItem, QString qsFindValue);

                void SetSelectedItem(CCustomItem* pSelectedItem);

                QTextEdit   *m_pFindText;
                QPushButton *m_pFindNextButton;
                QPushButton *m_pFindPrevButton;

                CFileTreeView *m_pFileTreeView;
                CCustomItem   *m_pSelectedItem;

                FileType m_enFileType;
        };
}

#endif // CMETAFILETREEWIDGET_H
