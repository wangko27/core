#ifndef CCUSTOMITEM_H
#define CCUSTOMITEM_H

#include <QStandardItem>

typedef std::vector<std::pair<QString, QString>> ItemArguments;

typedef enum
{
        CustomItemTypeRootRecord,
        CustomItemTypeRecord,
        CustomItemTypeStructure,
        CustomItemTypeValue,
        CustomItemTypeBuffer
} CustomItemType;

class CCustomItem : public QStandardItem
{
    public:
        CCustomItem();
        explicit CCustomItem(const QString &qsName, const QString& qsValue = "");

        void SetName(const QString& qsName);
        void SetValue(const QString& qsValue);
        void AddArguments(const std::vector<std::wstring>& arNames, const std::vector<std::wstring>& arValues);

        QString GetName() const;
        QString GetValue() const;
        ItemArguments GetArguments() const;
        CustomItemType GetType() const;

        virtual QVariant data(int role = Qt::UserRole + 1) const override;

    private:
        QString         m_qsName;
        QString         m_qsValue;
        ItemArguments   m_arArguments;
        CustomItemType  m_enType;
};

#endif // CCUSTOMITEM_H
