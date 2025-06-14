#include "mainviewmodel.h"

MyListModel::MyListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_data << "Apple" << "Orange" << "Banana";
}

int MyListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_data.size();
}

QVariant MyListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
        return m_data.at(index.row());

    return QVariant();
}

bool MyListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    m_data[index.row()] = value.toString();
    emit dataChanged(index, index, {role});
    return true;
}

Qt::ItemFlags MyListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

bool MyListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i)
        m_data.insert(row, "");
    endInsertRows();
    return true;
}

bool MyListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i)
        m_data.removeAt(row);
    endRemoveRows();
    return true;
}
