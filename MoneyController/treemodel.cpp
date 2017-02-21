#include "treemodel.h"
#include "treeview.h"
#include "treeheaderitem.h"
#include "dao.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    DAO::LoadModel(this);
}

TreeModel::~TreeModel()
{
    DAO::SaveModel(this);
    delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return static_cast<TreeItem*>(index.internalPointer())->flags();
}


QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}


bool TreeModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if( role != Qt::EditRole)
        return false;

    TreeItem* item = static_cast<TreeItem*> ( index.internalPointer() );
    item->ItemData( index.column() ) = value;

    return true;
}

void TreeModel::insertChild(QModelIndex& index)
{
    TreeItem* item = GetItemByIndex(index);

    beginInsertRows(index.parent(),index.row()+item->childCount(),index.row()+item->childCount()+1);
    item->appendNewChild();
    endInsertRows();
}

void TreeModel::deleteItem(QModelIndex& index)
{
    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    beginRemoveRows(index,index.row(),index.row());
    item->parent()->removeFromTree(item);
    endRemoveRows();
}

TreeItem* TreeModel::GetItemByIndex(QModelIndex &index)
{
    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    if(!item)
        item = rootItem;

    return item;
}
