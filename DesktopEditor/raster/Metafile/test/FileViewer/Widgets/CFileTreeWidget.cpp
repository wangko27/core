#include "CFileTreeWidget.h"

#include <QMenu>
#include <QBoxLayout>

#include "CRecordCreator.h"
#include "RecordWidgets/Common.h"

namespace Widgets
{
        CFileTreeWidget::CFileTreeWidget(QWidget *parent)
                : QWidget(parent),
                  m_pFindText(NULL),
                  m_pFindNextButton(NULL),
                  m_pFindPrevButton(NULL),
                  m_pFileTreeView(NULL),
                  m_nIndexSelectedItem(0),
                  m_pSelectedItem(NULL)
        {
                QVBoxLayout *pLayout = new QVBoxLayout(this);
                QHBoxLayout *pFindLayout = new QHBoxLayout();

                m_pFindText = new QTextEdit();
                AlignTextEdit(m_pFindText);

                m_pFindNextButton = new QPushButton("Find next");
                m_pFindPrevButton = new QPushButton("Find prev");

                connect(m_pFindNextButton, &QPushButton::clicked, this, &CFileTreeWidget::slotFindNext);
                connect(m_pFindPrevButton, &QPushButton::clicked, this, &CFileTreeWidget::slotFindPrev);

                QFont oFont = m_pFindText->font();
                oFont.setPointSize(oFont.pointSize());

                m_pFindNextButton->setFont(oFont);
                m_pFindPrevButton->setFont(oFont);

                pFindLayout->addWidget(m_pFindText);
                pFindLayout->addWidget(m_pFindNextButton);
                pFindLayout->addWidget(m_pFindPrevButton);

                pLayout->addLayout(pFindLayout);

                m_pFileTreeView = new CFileTreeView();

                connect(m_pFileTreeView, &CFileTreeView::clickedRightMouseButton, this, &CFileTreeWidget::slotRBClickedOnMetafileTree);
                connect(m_pFileTreeView, &CFileTreeView::signalDeleteItem, this,  &CFileTreeWidget::slotDeleteItem);

                pLayout->addWidget(m_pFileTreeView);
        }

        CFileTreeWidget::~CFileTreeWidget()
        {
                if (NULL != m_pFindText)
                        delete m_pFindText;
                if (NULL != m_pFindNextButton)
                        delete m_pFindNextButton;
                if (NULL != m_pFindPrevButton)
                        delete m_pFindPrevButton;
                if (NULL != m_pFileTreeView)
                        delete m_pFileTreeView;



                m_pSelectedItem = NULL;
        }

        void CFileTreeWidget::Clear()
        {
                ClearTree();

                if (NULL != m_pFindText)
                        m_pFindText->clear();

                m_nIndexSelectedItem = 0;
                m_pSelectedItem = NULL;
        }

        void CFileTreeWidget::setItemDelegate(CTextEditDelegate *pTextEditDelegate)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->setItemDelegate(pTextEditDelegate);
        }

        void CFileTreeWidget::expandAll()
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->expandAll();
        }

        void CFileTreeWidget::collapseAll()
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->collapseAll();
        }

        QAbstractItemModel* CFileTreeWidget::model()
        {
                if (NULL != m_pFileTreeView)
                        return m_pFileTreeView->model();

                return NULL;
        }

        void CFileTreeWidget::setFrameShadow(QFrame::Shadow enShadow)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->setFrameShadow(enShadow);
        }

        void CFileTreeWidget::setSelectionBehavior(QAbstractItemView::SelectionBehavior unBehavior)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->setSelectionBehavior(unBehavior);
        }

        void CFileTreeWidget::setAutoExpandDelay(int nDelay)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->setAutoExpandDelay(nDelay);
        }

        void CFileTreeWidget::setRootIsDecorated(bool bShow)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->setRootIsDecorated(bShow);
        }

        void CFileTreeWidget::setAnimated(bool bEnable)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->setAnimated(bEnable);
        }

        QHeaderView* CFileTreeWidget::header()
        {
                if (NULL != m_pFileTreeView)
                        return m_pFileTreeView->header();

                return NULL;
        }

        bool CFileTreeWidget::SetFile(const std::wstring &wsXmlFilePath)
        {
                if (NULL != m_pFileTreeView)
                        return m_pFileTreeView->SetFile(wsXmlFilePath);

                return false;
        }

        bool CFileTreeWidget::IsClearTree()
        {
                if (NULL != m_pFileTreeView)
                        return m_pFileTreeView->IsClear();

                return false;
        }

        void CFileTreeWidget::SetMode(bool bLightMode)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->SetMode(bLightMode);
        }

        void CFileTreeWidget::ClearTree()
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->Clear();
        }

        QMap<QString, unsigned int> CFileTreeWidget::GetStatistics()
        {
                if (NULL != m_pFileTreeView)
                {
                        QMap<QString, unsigned int> mStatictics;
                        unsigned int unIndexRecord = 0;

                        QModelIndex oMainIndex = m_pFileTreeView->model()->index(0, 0);
                        QModelIndex oIndex = oMainIndex.child(unIndexRecord++, 0);

                        while (oIndex.isValid())
                        {
                                QString qsNameRecord = oIndex.data(1).toString();
                                qsNameRecord = qsNameRecord.mid(1, qsNameRecord.length() - 2);
                                ++mStatictics[qsNameRecord];
                                oIndex = oMainIndex.child(unIndexRecord++, 0);
                        }

                        return mStatictics;
                }

                return {};
        }

        bool CFileTreeWidget::SaveInXmlFile(const std::wstring &wsSaveFilePath)
        {
                if (NULL != m_pFileTreeView)
                        return m_pFileTreeView->SaveInXmlFile(wsSaveFilePath);

                return false;
        }

        void CFileTreeWidget::EditItem(CCustomItem *pStandardItem)
        {
                if (NULL != m_pFileTreeView)
                        m_pFileTreeView->EditItem(pStandardItem);
        }

        void CFileTreeWidget::mouseReleaseEvent(QMouseEvent *event)
        {
                m_pSelectedItem = NULL;
                QWidget::mouseReleaseEvent(event);
        }

        void CFileTreeWidget::slotFindNext()
        {
                if (NULL == m_pFindText || NULL == m_pFileTreeView || IsClearTree())
                        return;

                QString qsFindText = m_pFindText->toPlainText().toLower();

                if (NULL != m_pSelectedItem)
                        m_pSelectedItem->setData(false, 5);

                if (qsFindText.isEmpty())
                        return;

                QModelIndex oMainIndex = m_pFileTreeView->model()->index(0, 0);
                QModelIndex oIndex = oMainIndex.child(m_nIndexSelectedItem++, 0);

                while (oIndex.isValid())
                {
                        QString qsTextItem = oIndex.data(2).toString().toLower();
                        if (qsTextItem.contains(qsFindText))
                        {
                                QStandardItem *pStandardItem = static_cast<QStandardItem*>(oIndex.internalPointer());
                                QStandardItem *pItem = pStandardItem->child(oIndex.row(), oIndex.column());

                                m_pFileTreeView->scrollTo(oIndex);

                                m_pSelectedItem = pItem;
                                pItem->setData(true, 5);
                                m_pFileTreeView->update();
                                return;
                        }
                        oIndex = oMainIndex.child(m_nIndexSelectedItem++, 0);
                }

                m_nIndexSelectedItem = 0;
        }

        void CFileTreeWidget::slotFindPrev()
        {
                if (NULL == m_pFindText || NULL == m_pFileTreeView || m_pFindText->toPlainText().isEmpty() || IsClearTree() || m_nIndexSelectedItem == 0)
                        return;

                if (NULL == m_pFindText || NULL == m_pFileTreeView || IsClearTree())
                        return;

                QString qsFindText = m_pFindText->toPlainText().toLower();

                if (NULL != m_pSelectedItem)
                        m_pSelectedItem->setData(false, 5);

                if (qsFindText.isEmpty())
                        return;

                QModelIndex oMainIndex = m_pFileTreeView->model()->index(0, 0);
                QModelIndex oIndex = oMainIndex.child(--m_nIndexSelectedItem - 1, 0);

                while (oIndex.isValid())
                {
                        QString qsTextItem = oIndex.data(2).toString().toLower();
                        if (qsTextItem.contains(qsFindText))
                        {
                                QStandardItem *pStandardItem = static_cast<QStandardItem*>(oIndex.internalPointer());
                                QStandardItem *pItem = pStandardItem->child(oIndex.row(), oIndex.column());

                                m_pFileTreeView->scrollTo(oIndex);

                                m_pSelectedItem = pItem;
                                pItem->setData(true, 5);
                                m_pFileTreeView->update();
                                return;
                        }
                        oIndex = oMainIndex.child(--m_nIndexSelectedItem - 1, 0);
                }

                m_nIndexSelectedItem = 0;
        }

        void CFileTreeWidget::slotRBClickedOnMetafileTree(QPoint oPoint)
        {
                if (NULL == model())
                        return;

                QModelIndex oModelIndex = m_pFileTreeView->indexAt(oPoint);

                if (!oModelIndex.isValid())
                        return;

                CCustomItem *pStandardItem = static_cast<CCustomItem*>(oModelIndex.internalPointer());
                CCustomItem *pItem = (CCustomItem*)pStandardItem->child(oModelIndex.row(), oModelIndex.column());

                QMenu oContextMenu;

                oContextMenu.addAction("Edit", this, [this, pItem](){m_pFileTreeView->EditItem(pItem);});

                if (true == pItem->data(3))
                {
                        oContextMenu.addAction("Insert before", this, [this, pStandardItem, oModelIndex](){InsertRecord(pStandardItem, oModelIndex.row());});
                        oContextMenu.addAction("Insert after", this,  [this, pStandardItem, oModelIndex](){InsertRecord(pStandardItem, oModelIndex.row(), false);});
                }

                oContextMenu.exec(m_pFileTreeView->mapToGlobal(oPoint));
        }

        void CFileTreeWidget::slotDeleteItem(CCustomItem *pDeletedItem)
        {
                if (pDeletedItem == m_pSelectedItem)
                {
                        m_pSelectedItem = NULL;
                        m_nIndexSelectedItem = 0;
                }
                else
                        --m_nIndexSelectedItem;
        }

        void CFileTreeWidget::InsertRecord(CCustomItem *pParentItem, unsigned int unRow, bool bAfterRecord)
        {
                if (NULL == pParentItem)
                        return;

                CRecordCreator *pRecordCreator = new CRecordCreator((QWidget*)parent());

                QStandardItem *pItem = pRecordCreator->CreateRecord();

                if (NULL != pItem)
                {
                        pParentItem->insertRow(unRow + ((bAfterRecord) ? 0 : 1), pItem);
        //                if (m_pMainWindow->SaveInXmlFile(L"Temp.xml") &&
        //                    m_pMainWindow->ConvertToEmf(L"Temp.xml"))
        //                        m_pMainWindow->DisplayingFile(L"TempFile.emf", false);
                }
        }
}
