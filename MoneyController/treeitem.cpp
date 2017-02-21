#include "treeitem.h"
#include <QVariant>
#include "Column.h"

long TreeItem::NextCode = 100;

TreeItem::TreeItem(const QHash< Column, QVariant >  &data, TreeItem *parent)
{
    Code = NextCode++;
    parentItem = parent;
    if(data.size())
        itemData=data;
    else
        itemData = EmptyData();
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

Qt::ItemFlags TreeItem::flags()
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

MenuFlags TreeItem::menuFlags()
{
    MenuFlags ret = MF_NoMenuFlags;

    ret |= MF_AddMenuVisible;

    ret |= MF_DeleteMenuVisible;
    ret |= childCount() == 0 ? ret : MF_DeleteMenuDisabled;
    ret |= parentItem && row() == parentItem->childCount() - 1 ?
               ret : MF_DeleteMenuDisabled;

    return ret;
}

QString TreeItem::GetChildName()
{
    return "";
}

QHash< Column, QVariant > TreeItem::ColumnsData()
{
    QHash< Column, QVariant > columns_data;

    columns_data[DATE] = // "Дата";
    columns_data[INFO_DATA] = "Данные";

    return columns_data;
}

QHash< Column, QVariant > TreeItem::EmptyData()
{
    QHash< Column, QVariant > empty_data;

    empty_data[DATE] = 0;
    empty_data[INFO_DATA] = "Информация по заказу";

    for (int i = START + 1; i < LAST; ++i)
        empty_data[Column(i)] = QVariant();

    return empty_data;
}
