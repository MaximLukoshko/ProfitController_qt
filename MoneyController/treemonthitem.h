#ifndef TREEMONTHITEM_H
#define TREEMONTHITEM_H

#include "treeitem.h"
#include "Month.h"
class TreeMonthItem : public TreeItem
{
public:
    TreeMonthItem( int month , TreeItem *parent = NULL, const QHash< Column, QVariant >  &data = QHash< Column, QVariant >());

    // TreeItem interface
public:
    virtual void appendNewChild();

protected:
    virtual QString GetChildName();
};

#endif // TREEMONTHITEM_H
