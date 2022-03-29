#include "CFileTreeView.h"

#include <QFile>
#include <QMessageBox>
#include <QMouseEvent>
#include "CTextEditDelegate.h"

#include "../CEditItemWidget.h"

CFileTreeView::CFileTreeView(QWidget *parent) :
    QTreeView(parent)
{}

CFileTreeView::~CFileTreeView()
{}

bool CFileTreeView::SetFile(const std::wstring &wsXmlFilePath)
{
        setModel(nullptr);

        if (wsXmlFilePath.empty())
                return false;

        XmlUtils::CXmlNode oXmlRootNode;

        if (!oXmlRootNode.FromXmlFile(wsXmlFilePath))
                return false;

        setHeaderHidden(true);

        QStandardItemModel *pStandardItemModel = new QStandardItemModel;
        CCustomItem *pStandardItem = new CCustomItem(QString::fromStdWString(oXmlRootNode.GetName()));

        pStandardItem->setEditable(false);
        pStandardItem->SetType(CustomItemTypeRootRecord);

        ReadXmlNode(oXmlRootNode, pStandardItem, 1);

        pStandardItemModel->appendRow(pStandardItem);
        setModel(pStandardItemModel);

        return true;
}

bool CFileTreeView::IsClear()
{
        return NULL == model();
}

void CFileTreeView::SetMode(bool bLightMode)
{
        if (dynamic_cast<CTextEditDelegate*>(itemDelegate()) != nullptr)
        {
                CTextEditDelegate *pTextEditDelegate = static_cast<CTextEditDelegate*>(itemDelegate());
                pTextEditDelegate->SetMode(bLightMode);
                pTextEditDelegate->updateEditorGeometry(this, QStyleOptionViewItem(), QModelIndex());
        }
}

void CFileTreeView::Clear()
{
        QAbstractItemModel *pModel = model();
        if (NULL != pModel)
        {
                delete pModel;
                setModel(NULL);
        }
}

bool CFileTreeView::SaveInXmlFile(const std::wstring& wsSaveFilePath)
{
        QStandardItemModel *pStandardItemModel = (QStandardItemModel*)model();
        CCustomItem *pRootNode = (CCustomItem*)pStandardItemModel->item(0);

        XmlUtils::CXmlWriter oXmlWriter;

        oXmlWriter.WriteString(L"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");

        WriteXmlNode(oXmlWriter, pRootNode);

        return oXmlWriter.SaveToFile(wsSaveFilePath);
}

void CFileTreeView::ReadXmlNode(XmlUtils::CXmlNode& oXmlNode, CCustomItem* pCustomItem, unsigned int unLevel)
{
        pCustomItem->SetName(QString::fromStdWString(oXmlNode.GetName()));

        if (2 == unLevel)
                pCustomItem->SetType(CustomItemTypeRecord);

        ReadArguments(oXmlNode, pCustomItem);

        XmlUtils::CXmlNodes oXmlChilds;

        if (oXmlNode.GetChilds(oXmlChilds))
        {
                for (unsigned int i = 0; i < oXmlChilds.GetCount(); ++i)
                {
                        XmlUtils::CXmlNode oXmlChild;
                        if (oXmlChilds.GetAt(i, oXmlChild))
                        {
                                CCustomItem *pStandardItem = new CCustomItem;

                                ReadXmlNode(oXmlChild, pStandardItem, unLevel + 1);

                                pCustomItem->appendRow(pStandardItem);
                        }
                }
        }
        else
        {
                pCustomItem->SetValue(QString::fromStdWString(oXmlNode.GetText()));
        }
}

void CFileTreeView::ReadArguments(XmlUtils::CXmlNode &oXmlNode, CCustomItem *pStandartItem)
{
        if (NULL != pStandartItem && 0 != oXmlNode.GetAttributesCount())
        {
                std::vector<std::wstring> arAttributeName, arAttributeValue;

                oXmlNode.GetAllAttributes(arAttributeName, arAttributeValue);

                pStandartItem->AddArguments(arAttributeName, arAttributeValue);
        }
}

std::wstring StringNormalization(std::wstring wsString)
{
    std::wstring wsText;
    for (wchar_t wChar : wsString)
        if (wChar == L'<')
               wsText += L"&lt;";
        else if (wChar == L'>')
               wsText += L"&gt;";
        else if (wChar == L'&')
               wsText += L"&amp;";
        else if (wChar == L'\'')
               wsText += L"&apos;";
        else if (wChar == L'"')
               wsText += L"&quot;";

        else wsText += wChar;
    return wsText;
}

void CFileTreeView::WriteXmlNode(XmlUtils::CXmlWriter &oXmlWriter, CCustomItem *oStandartItem)
{
        unsigned int unCountNodes = oStandartItem->rowCount();

        QString qsNodeText = oStandartItem->data(0).toString();

        unsigned int unFirstQuotationMark = qsNodeText.indexOf(L'>');
        unsigned int unLastSlash = qsNodeText.lastIndexOf(L'/');

        std::wstring wsName = qsNodeText.mid(1, ((unLastSlash > unFirstQuotationMark) ? (unFirstQuotationMark) : (unLastSlash)) - 1).toStdWString();

        if (oStandartItem->rowCount() == 0)
        {
                std::wstring wsValue;

                if (unLastSlash > unFirstQuotationMark)
                        wsValue = qsNodeText.mid(unFirstQuotationMark + 1, unLastSlash - unFirstQuotationMark - 2).toStdWString();

                oXmlWriter.WriteNode(wsName, StringNormalization(wsValue));

                return;
        }

        oXmlWriter.WriteNodeBegin(wsName);

        for (unsigned int unIndexNode = 0; unIndexNode < unCountNodes; ++unIndexNode)
        {
                CCustomItem *pNode = (CCustomItem*)oStandartItem->child(unIndexNode);
                WriteXmlNode(oXmlWriter, pNode);
        }

        oXmlWriter.WriteNodeEnd(wsName);
}

void CFileTreeView::EditItem(CCustomItem *pStandardItem)
{
        if (NULL == pStandardItem)
                return;

        Widgets::CEditItemWidget *pEditItemWidget = new Widgets::CEditItemWidget;

        pEditItemWidget->SetItem(pStandardItem);

        if (QDialog::Accepted == pEditItemWidget->exec())
        {

        }

//        connect(pEditItemWidget, &CEditItemWidget::signalDeleteItem, this, &CFileTreeView::slotDeleteItem);

//        pEditItemWidget->SetMainWindow((MainWindow*)parent()->parent()->parent()->parent());
//        pEditItemWidget->SetItem(pStandardItem);
//        pEditItemWidget->show();
}

void CFileTreeView::slotDeleteItem(CCustomItem *pDeletedItem)
{
        emit signalDeleteItem(pDeletedItem);
}

void CFileTreeView::mouseReleaseEvent(QMouseEvent *event)
{
        if (event->button() == Qt::RightButton)
                emit clickedRightMouseButton(event->pos());
        else
                QTreeView::mouseReleaseEvent(event);
}

