#include "treeyearitem.h"
#include "treemonthitem.h"

TreeYearItem::TreeYearItem(int year, TreeItem *parent, const QHash< Column, QVariant >  &data)
    : TreeItem(data, parent)
{
    itemData[YEAR] = year;
}


void TreeYearItem::appendNewChild()
{
    if( childCount() == 12 )
        return;

    int month = JANUARY;

    if( childCount() > 0 )
        month = child( childCount() - 1 )->ItemData(MONTH).toInt() + 1;

    TreeMonthItem* newItem = new TreeMonthItem(month, this);
    childItems.append(newItem);
}

QString TreeYearItem::GetChildName()
{
    return "месяц";
}

MenuFlags TreeYearItem::menuFlags()
{
    MenuFlags ret = TreeItem::menuFlags();
    ret |= childCount() < 12 ?  ret : MF_AddMenuDisabled;
    return ret;
}
