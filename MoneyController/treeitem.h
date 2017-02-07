#ifndef TREEITEM_H
#define TREEITEM_H

#include <QHash>
#include "Column.h"
#include <QAction>


class TreeItem
 {
 public:
     TreeItem(const QHash< Column, QVariant > &data = QHash< Column, QVariant >() , TreeItem *parent = NULL);
     virtual ~TreeItem();

     void appendChild(TreeItem *child);

     virtual void appendNewChild() = 0;

     void removeFromTree(TreeItem *item_to_delete);

     TreeItem *child(int row);
     int childCount() const;
     int columnCount() const;
     virtual QVariant data(int column) const;
     int row() const;
     TreeItem *parent();

     virtual QVariant& ItemData(int col);

     virtual Qt::ItemFlags flags();

     virtual QAction* CreateAddAction();
     virtual QAction* CreateDeleteAction();

protected:
     virtual QString GetChildName();
     static QHash< Column, QVariant > ColumnsData();
     static QHash< Column, QVariant > EmptyData();

 protected:
     QList<TreeItem*> childItems;
     QHash< Column, QVariant > itemData;
     TreeItem *parentItem;
 };

#endif // TREEITEM_H
