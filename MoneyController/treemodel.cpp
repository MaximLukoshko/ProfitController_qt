#include "treemodel.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    QHash<Column, QVariant> rootData;
    rootData[FIRST] = "Наименование" ;
    rootData[SECOND] = "Значение";
    rootItem = new TreeItem(rootData);

    rootItem->appendChild( new TreeItem(rootData) );
    rootItem->appendChild( new TreeItem(rootData) );

    rootItem->child(0)->appendChild( new TreeItem(rootData) );

    rootItem->child(1)->appendChild( new TreeItem(rootData) );
    rootItem->child(1)->child(0)->appendChild( new TreeItem(rootData) );
}

TreeModel::~TreeModel()
{
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

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
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
    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    if(!item)
        item = rootItem;

    beginInsertRows(index.parent(),index.row()+item->childCount(),index.row()+item->childCount()+1);
    item->appendChild(new TreeItem(QHash<Column, QVariant>()));
    endInsertRows();
}

void TreeModel::deleteItem(QModelIndex& index)
{
    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    beginRemoveRows(index,index.row(),index.row());
    item->parent()->removeFromTree(item);
    endRemoveRows();
}