#ifndef TREEORDERITEM_H
#define TREEORDERITEM_H

#include "treeitem.h"

class TreeOrderItem : public TreeItem
{
public:
    TreeOrderItem( TreeItem *parent = NULL, const QHash< Column, QVariant >  &data = QHash< Column, QVariant >() );

    // TreeItem interface
public:
    virtual void appendNewChild();

    // TreeItem interface
public:
    virtual MenuFlags menuFlags();
};

#endif // TREEORDERITEM_H
