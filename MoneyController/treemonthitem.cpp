#include "treemonthitem.h"
#include "treeorderitem.h"

TreeMonthItem::TreeMonthItem( int month, TreeItem *parent, const QHash< Column, QVariant >  &data)
    : TreeItem(data, parent)
{
    itemData[DATE] = month;
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


QVariant TreeMonthItem::data(int column) const
{
    if( column != DATE )
        return QVariant();

    int month = itemData[Column(column)].toInt();

    switch (month) {
        case JANUARY:
            return "Январь";
            break;
        case FEBRUARY:
            return "Февраль";
            break;
        case MARCH:
            return "Март";
            break;
        case APRIL:
            return "Апрель";
            break;
        case MAY:
            return "Май";
            break;
        case JUNE:
            return "Июнь";
            break;
        case JULY:
            return "Июль";
            break;
        case AUGUST:
            return "Август";
            break;
        case SEPTEMBER:
            return "Сентябрь";
            break;
        case OCTOBER:
            return "Октябрь";
            break;
        case NOVEMBER:
            return "Ноябрь";
            break;
        case DECEMBER:
            return "Декабрь";
            break;
        default:
            return "";
            break;
    }

    return "";
}
