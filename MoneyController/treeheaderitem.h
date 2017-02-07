#ifndef TREEHEADERITEM_H
#define TREEHEADERITEM_H

#include "treeitem.h"

class TreeHeaderItem : public TreeItem
{
public:
    TreeHeaderItem( TreeItem *parent = NULL, const QHash< Column, QVariant >  &data = QHash< Column, QVariant >());

    // TreeItem interface
public:
    virtual void appendNewChild();

protected:
    virtual QString GetChildName();
};

#endif // TREEHEADERITEM_H
