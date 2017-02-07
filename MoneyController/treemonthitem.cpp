#include "treemonthitem.h"
#include "treeorderitem.h"

TreeMonthItem::TreeMonthItem( int month, TreeItem *parent, const QHash< Column, QVariant >  &data)
    : TreeItem(data, parent)
{
    itemData[MONTH] = month;
}


void TreeMonthItem::appendNewChild()
{
    TreeOrderItem* newItem = new TreeOrderItem(this);
    childItems.append(newItem);
}

QString TreeMonthItem::GetChildName()
{
    return "Заказ";
}
