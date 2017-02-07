#include "treeitem.h"
#include <QVariant>
#include "Column.h"

TreeItem::TreeItem(const QHash< Column, QVariant >  &data, TreeItem *parent)
{
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

QAction* TreeItem::CreateAddAction()
{
    return new QAction("Новый " + this->GetChildName(), 0);
}

QAction* TreeItem::CreateDeleteAction()
{
    QAction* del_act = new QAction("Удалить", 0);
    del_act->setEnabled( childCount() == 0 ? true : false );
    return del_act;
}

QString TreeItem::GetChildName()
{
    return "";
}

QHash< Column, QVariant > TreeItem::ColumnsData()
{
    QHash< Column, QVariant > columns_data;

    columns_data[YEAR] = "Год";
    columns_data[MONTH] = "Месяц";

    return columns_data;
}

QHash< Column, QVariant > TreeItem::EmptyData()
{
    QHash< Column, QVariant > empty_data;

    empty_data[YEAR] = "Год";
    empty_data[MONTH] = "Месяц";

    for (int i = START + 1; i < LAST; ++i)
        empty_data[Column(i)] = QVariant();

    return empty_data;
}
