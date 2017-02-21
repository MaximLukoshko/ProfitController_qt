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
    MenuFlags ret = MF_NoMenuFlags;
    ret |= MF_DeleteMenuVisible;
    return ret;
}


Qt::ItemFlags TreeOrderItem::flags()
{
    return TreeItem::flags() | Qt::ItemIsEditable;
}


QVariant TreeOrderItem::data(int column) const
{
    if(column==DATE)
        return 0 < itemData[DATE].toInt() ?  itemData[DATE].toInt() : QVariant( "День" );

    return TreeItem::data(column);
}
