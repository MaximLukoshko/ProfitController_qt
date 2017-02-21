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

    // TreeItem interface
public:
    virtual Qt::ItemFlags flags();

    // TreeItem interface
public:
    virtual QVariant data(int column) const;
};

#endif // TREEORDERITEM_H
