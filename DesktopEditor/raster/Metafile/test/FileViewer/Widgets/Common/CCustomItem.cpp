#include "CCustomItem.h"

CCustomItem::CCustomItem()
{}

CCustomItem::CCustomItem(const QString &qsName, const QString &qsValue)
        : m_qsName(qsName), m_qsValue(qsValue)
{}

void CCustomItem::SetName(const QString &qsName)
{
        m_qsName = qsName;
}

void CCustomItem::SetValue(const QString &qsValue)
{
        m_qsValue = qsValue;
}

void CCustomItem::AddArguments(const std::vector<std::wstring> &arNames, const std::vector<std::wstring> &arValues)
{
        for (unsigned int unIndex = 0; unIndex < std::min(arNames.size(), arValues.size()); ++unIndex)
                m_arArguments.push_back(std::pair<QString, QString>(QString::fromStdWString(arNames[unIndex]), QString::fromStdWString(arValues[unIndex])));
}

void CCustomItem::SetArguments(const ItemArguments &arArguments)
{
        m_arArguments = arArguments;
}

void CCustomItem::SetType(CustomItemType enType)
{
        m_enType = enType;
}

QString CCustomItem::GetName() const
{
        return m_qsName;
}

QString CCustomItem::GetValue() const
{
        return m_qsValue;
}

ItemArguments CCustomItem::GetArguments() const
{
        return m_arArguments;
}

unsigned int CCustomItem::GetCountArguments() const
{
        return m_arArguments.size();
}

CustomItemType CCustomItem::GetType() const
{
        return m_enType;
}

QVariant CCustomItem::data(int role) const
{
        if (Qt::DisplayRole == role)
        {
                QString qsItem = QString("<%1").arg(m_qsName);

                for (const std::pair<QString, QString>& oArgument : m_arArguments)
                        qsItem += QString(" %1=\"%2\"").arg(oArgument.first).arg(oArgument.second);

                if (hasChildren())
                {
                        qsItem += ">";
                        return qsItem;
                }

                if (m_qsValue.isEmpty())
                {
                        qsItem += "/>";
                        return qsItem;
                }

                qsItem += QString(">%1</%2>").arg(m_qsValue).arg(m_qsName);

                return qsItem;
        }
        else
                return QStandardItem::data(role);
}


