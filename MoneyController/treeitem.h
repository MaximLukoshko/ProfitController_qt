#ifndef TREEITEM_H
#define TREEITEM_H

#include <QHash>
#include "Column.h"
#include <QAction>


class TreeItem
 {
 public:
     TreeItem(const QHash< Column, QVariant > &data, TreeItem *parent = 0);
     ~TreeItem();

     void appendChild(TreeItem *child);
     void removeFromTree(TreeItem *item_to_delete);

     TreeItem *child(int row);
     int childCount() const;
     int columnCount() const;
     QVariant data(int column) const;
     int row() const;
     TreeItem *parent();
     QVariant& ItemData(int col);



     QAction* GetAddAction();

private:
     QString GetChildName();

 private:
     QList<TreeItem*> childItems;
     QHash< Column, QVariant > itemData;
     TreeItem *parentItem;
 };

#endif // TREEITEM_H
