#include "CFileTreeWidget.h"

#include <QMenu>
#include <QBoxLayout>

#include "CRecordCreator.h"
#include "RecordWidgets/Common.h"

#include "CEditItemWidget.h"
#include "../../../../common/Directory.h"

namespace Widgets
{
        CFileTreeWidget::CFileTreeWidget(QWidget *parent)
                : QWidget(parent),
                  m_pFindText(NULL),
                  m_pFindNextButton(NULL),
                  m_pFindPrevButton(NULL),
                  m_pFileTreeView(NULL),
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

                pLayout->addWidget(m_pFileTreeView);


                CTextEditDelegate *pTextEditDelegate = new CTextEditDelegate(this);

                QFont *pFont = new QFont;
                pFont->setPointSize(13);

                setFont(*pFont);

                pTextEditDelegate->SetFont(pFont);

                m_pFileTreeView->setItemDelegate(pTextEditDelegate);
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

                m_pSelectedItem = NULL;
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

        bool CFileTreeWidget::SetFile(const std::wstring &wsXmlFilePath, FileType enType)
        {
                m_enFileType = enType;

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

                        QStandardItemModel *pStandardItemModel = (QStandardItemModel*)m_pFileTreeView->model();
                        QModelIndex oRootIndex = pStandardItemModel->index(0, 0);
                        CCustomItem *pRootItem = (CCustomItem*)pStandardItemModel->itemFromIndex(oRootIndex);

                        ProcessNode(pRootItem, mStatictics);

                        return mStatictics;
                }

                return {};
        }

        void CFileTreeWidget::ProcessNode(const CCustomItem *pCustomItem, Statistics &mStatistics)
        {
                if (NULL == pCustomItem)
                        return;

                QString qsName = pCustomItem->GetName();

                if (CustomItemTypeRecord == pCustomItem->GetType())
                        ++mStatistics[pCustomItem->GetName()];

                for (unsigned short unIndex = 0; unIndex < pCustomItem->rowCount(); ++unIndex)
                        ProcessNode((CCustomItem*)pCustomItem->child(unIndex), mStatistics);
        }

        bool CFileTreeWidget::SaveInXmlFile(const std::wstring &wsSaveFilePath)
        {
                if (NULL != m_pFileTreeView)
                        return m_pFileTreeView->SaveInXmlFile(wsSaveFilePath);

                return false;
        }

        void CFileTreeWidget::EditItem(CCustomItem *pStandardItem)
        {
                if (NULL == pStandardItem)
                        return;

                m_pSelectedItem = pStandardItem;

                CEditItemWidget *pEditItemWidget = new CEditItemWidget;

                connect(pEditItemWidget, &CEditItemWidget::signalDeleteItem, this, [this](){slotDeleteItem();});

                pEditItemWidget->SetItem(pStandardItem);

                if (QDialog::Accepted == pEditItemWidget->exec())
                {
                        pEditItemWidget->Update();

                        QString qsXmlFilePath = QString::fromStdWString(NSFile::GetProcessDirectory() + L"\\Temp.xml");

                        if (SaveInXmlFile(qsXmlFilePath.toStdWString()))
                                emit signalUpdate(qsXmlFilePath);
                }
        }

        void CFileTreeWidget::mouseReleaseEvent(QMouseEvent *event)
        {
//                m_pSelectedItem = NULL;
                QWidget::mouseReleaseEvent(event);
        }

        bool CFileTreeWidget::FindLower(CCustomItem* pCustomItem, QString qsFindValue)
        {
                if (NULL == pCustomItem)
                        return false;

                CCustomItem *pChild;
                for (unsigned short unIndex = 0; unIndex < pCustomItem->rowCount(); ++unIndex)
                {
                        pChild = (CCustomItem*)pCustomItem->child(unIndex);
                        if (qsFindValue == pChild->GetName().toLower())
                        {
                                SetSelectedItem(pChild);
                                return true;
                        }
                        if (FindLower(pChild, qsFindValue))
                                return true;
                }

                return false;
        }

        bool CFileTreeWidget::FindUpperLower(CCustomItem *pCustomItem, QString qsFindValue)
        {
                if (NULL == pCustomItem)
                        return false;

                CCustomItem *pParentItem = (CCustomItem*)pCustomItem->parent();

                if (NULL == pParentItem)
                        return false;

                for (unsigned int unIndex = pCustomItem->row() + 1; unIndex < pParentItem->rowCount(); ++unIndex)
                {
                        CCustomItem *pNextChild = (CCustomItem*)pParentItem->child(unIndex);

                        if (NULL == pNextChild)
                                return false;

                        if (qsFindValue == pNextChild->GetName().toLower())
                        {
                                SetSelectedItem(pNextChild);
                                return true;
                        }

                        if (FindLower(pNextChild, qsFindValue))
                                return true;
                }

                return false;
        }

        bool CFileTreeWidget::FindUpperUpper(CCustomItem *pCustomItem, QString qsFindValue)
        {
                if (NULL == pCustomItem)
                        return false;

                CCustomItem *pParentItem = (CCustomItem*)pCustomItem->parent();

                if (NULL == pParentItem)
                        return false;

                for (unsigned int unIndex = pCustomItem->row() - 1; unIndex > 0; --unIndex)
                {
                        CCustomItem *pPrevChild = (CCustomItem*)pParentItem->child(unIndex);

                        if (NULL == pPrevChild)
                                return false;

                        if (qsFindValue == pPrevChild->GetName().toLower())
                        {
                                SetSelectedItem(pPrevChild);
                                return true;
                        }

                        if (FindLower(pPrevChild, qsFindValue))
                                return true;
                }

                return false;
        }

        void CFileTreeWidget::slotFindNext()
        {
                if (NULL == m_pFindText || NULL == m_pFileTreeView || IsClearTree())
                        return;

                QString qsFindText = m_pFindText->toPlainText().toLower();

                CCustomItem *pStartItem;

                if (NULL != m_pSelectedItem)
                        pStartItem = m_pSelectedItem;
                else
                {
                        QStandardItemModel *pStandardItemModel = (QStandardItemModel*)m_pFileTreeView->model();
                        QModelIndex oRootIndex = pStandardItemModel->index(0, 0);
                        pStartItem = (CCustomItem*)pStandardItemModel->itemFromIndex(oRootIndex);
                }

                if (FindLower(pStartItem, qsFindText))
                        return;

                if (!FindUpperLower(pStartItem, qsFindText))
                        SetSelectedItem(NULL);
        }

        void CFileTreeWidget::slotFindPrev()
        {
                if (NULL == m_pFindText || NULL == m_pFileTreeView || IsClearTree() || NULL == m_pSelectedItem)
                        return;

                QString qsFindText = m_pFindText->toPlainText().toLower();

                CCustomItem *pStartItem = m_pSelectedItem;

                if (!FindUpperUpper(pStartItem, qsFindText))
                        SetSelectedItem(NULL);
        }

        void CFileTreeWidget::slotRBClickedOnMetafileTree(QPoint oPoint)
        {
                if (NULL == model())
                        return;

                QModelIndex oModelIndex = m_pFileTreeView->indexAt(oPoint);

                if (!oModelIndex.isValid())
                        return;

                CCustomItem *pStandardItem = static_cast<CCustomItem*>(oModelIndex.internalPointer());

                if (NULL == pStandardItem)
                        return;

                CCustomItem *pItem = (CCustomItem*)pStandardItem->child(oModelIndex.row(), oModelIndex.column());

                if (NULL == pItem || CustomItemTypeRootRecord == pItem->GetType())
                        return;

                QMenu oContextMenu;

                oContextMenu.addAction("Edit", this, [this, pItem](){EditItem(pItem);});

                if (CustomItemTypeRecord == pItem->GetType())
                {
                        oContextMenu.addAction("Insert before", this, [this, pStandardItem, oModelIndex](){InsertRecord(pStandardItem, oModelIndex.row());});
                        oContextMenu.addAction("Insert after", this,  [this, pStandardItem, oModelIndex](){InsertRecord(pStandardItem, oModelIndex.row(), false);});
                }

                oContextMenu.exec(m_pFileTreeView->mapToGlobal(oPoint));
        }

        void CFileTreeWidget::slotDeleteItem()
        {
                if (NULL != m_pSelectedItem)
                {
                        CCustomItem *pParent = (CCustomItem*)m_pSelectedItem->parent();

                        if (NULL == pParent)
                                return;

                        pParent->removeRow(m_pSelectedItem->index().row());

                        m_pSelectedItem = NULL;

                        QString qsXmlFilePath = QString::fromStdWString(NSFile::GetProcessDirectory() + L"/Temp.png");

                        if (SaveInXmlFile(qsXmlFilePath.toStdWString()))
                                emit signalUpdate(qsXmlFilePath);
                }
        }

        void CFileTreeWidget::InsertRecord(CCustomItem *pParentItem, unsigned int unRow, bool bAfterRecord)
        {
                if (NULL == pParentItem)
                        return;

                if (FileTypeMetafile == m_enFileType)
                {
                        CEMFRecordCreator *pRecordCreator = new CEMFRecordCreator((QWidget*)parent());

                        QStandardItem *pItem = pRecordCreator->CreateRecord();

                        if (NULL != pItem)
                        {
                                pParentItem->insertRow(unRow + ((bAfterRecord) ? 0 : 1), pItem);

                                QString qsXmlFilePath = QString::fromStdWString(NSFile::GetProcessDirectory() + L"/Temp.png");

                                if (SaveInXmlFile(qsXmlFilePath.toStdWString()))
                                        emit signalUpdate(qsXmlFilePath);

                //                if (m_pMainWindow->SaveInXmlFile(L"Temp.xml") &&
                //                    m_pMainWindow->ConvertToEmf(L"Temp.xml"))
                //                        m_pMainWindow->DisplayingFile(L"TempFile.emf", false);
                        }
                }
                else if (FileTypeSvg == m_enFileType)
                {

                }
        }

        void CFileTreeWidget::SetSelectedItem(CCustomItem *pSelectedItem)
        {
                if (NULL != m_pSelectedItem)
                        m_pSelectedItem->setSelectable(false);

                m_pSelectedItem = pSelectedItem;

                if (NULL != m_pSelectedItem)
                {
                        m_pFileTreeView->scrollTo(m_pSelectedItem->index());
                        m_pSelectedItem->setSelectable(true);
                }
        }
}
