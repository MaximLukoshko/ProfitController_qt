#include "treeitem.h"
#include <QVariant>

TreeItem::TreeItem(const QHash< Column, QVariant >  &data, TreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}

TreeItem::~TreeItem()
{
    qDeleteAll(childItems);
}

void TreeItem::appendChild(TreeItem *item)
{
    item->parentItem = this;
    childItems.append(item);
}

void TreeItem::removeFromTree(TreeItem *item_to_delete)
{
    TreeItem* parent = item_to_delete->parent();

    parent->childItems.erase(parent->childItems.begin()+item_to_delete->row());
}

TreeItem* TreeItem::child(int row)
{
    return childItems.value(row);
}

int TreeItem::childCount() const
{
    return childItems.count();
}

int TreeItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::columnCount() const
{
    return LAST;
}

QVariant TreeItem::data(int column) const
{
    return itemData[Column(column)];
}

TreeItem* TreeItem::parent()
{
    return parentItem;
}

QVariant& TreeItem::ItemData(int col)
{
    return itemData[Column(col)];
}
