#ifndef CFILETREEVIEW_H
#define CFILETREEVIEW_H

#include <QTreeView>
#include <QStandardItemModel>
#include "CCustomItem.h"

#include "../../../../xml/include/xmlutils.h"

class CFileTreeView : public QTreeView
{
        Q_OBJECT
    public:
        explicit CFileTreeView(QWidget *parent = NULL);
        virtual ~CFileTreeView();

        bool SetFile(const std::wstring& wsXmlFilePath);
        bool IsClear();
        void SetMode(bool bLightMode);
        void Clear();

        bool SaveInXmlFile(const std::wstring& wsSaveFilePath);

        void EditItem(CCustomItem* pStandardItem);
    signals:
        void clickedRightMouseButton(QPoint oPoint);
        void clickedLeftMouseButton(QPoint oPoint);
        void signalDeleteItem(CCustomItem *pDeletedItem);

    private slots:
        void slotDeleteItem(CCustomItem *pDeletedItem);

    protected:
        virtual void mouseReleaseEvent(QMouseEvent* event) override;

    private:
        void ReadXmlNode(XmlUtils::CXmlNode& oXmlNode, CCustomItem* pStandartItem, unsigned int unLevel = 0);
        void ReadArguments(XmlUtils::CXmlNode& oXmlNode, CCustomItem* pStandartItem);
        void WriteXmlNode(XmlUtils::CXmlWriter& oXmlWriter, CCustomItem* pStandartItem);
};

#endif // CFILETREEVIEW_H
