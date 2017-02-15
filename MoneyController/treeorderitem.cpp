#include "treeorderitem.h"

TreeOrderItem::TreeOrderItem(TreeItem *parent, const QHash< Column, QVariant >  &data)
    : TreeItem(data, parent)
{
    itemData = ColumnsData();
}


void TreeOrderItem::appendNewChild()
{
}


MenuFlags TreeOrderItem::menuFlags()
{
    return TreeItem::menuFlags() & ~MF_AddMenuVisible;
}
