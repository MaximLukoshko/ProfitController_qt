#ifndef TREEYEARITEM_H
#define TREEYEARITEM_H

#include "treeitem.h"
#include "Month.h"

class TreeYearItem : public TreeItem
{
public:
    TreeYearItem(int year, TreeItem *parent = NULL, const QHash< Column, QVariant >  &data = QHash< Column, QVariant >());

    // TreeItem interface
public:
    virtual void appendNewChild();

protected:
    virtual QString GetChildName();

    // TreeItem interface
public:
    virtual MenuFlags menuFlags();
};

#endif // TREEYEARITEM_H
