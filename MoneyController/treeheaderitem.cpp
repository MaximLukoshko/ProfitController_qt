#include "treeheaderitem.h"
#include "treeyearitem.h"

TreeHeaderItem::TreeHeaderItem( TreeItem *parent, const QHash< Column, QVariant >  &data )
    : TreeItem(data, parent)
{
    itemData = ColumnsData();
}


void TreeHeaderItem::appendNewChild()
{
    int year = 2015;
    if( childCount() > 0 )
        year = child( childCount() - 1 )->ItemData(DATE).toInt() + 1;

    TreeYearItem* newItem = new TreeYearItem(year, this);
    childItems.append(newItem);
}

QString TreeHeaderItem::GetChildName()
{
    return "год";
}


MenuFlags TreeHeaderItem::menuFlags()
{
    return TreeItem::menuFlags() & ~MF_DeleteMenuVisible;
}
