#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractTableModel>
#include "Column.h"
#include "treeitem.h"
#include "treeheaderitem.h"
#include <QMetaType>
#include <QMenu>
#include <QModelIndex>
#include "dao.h"

class TreeModel : public QAbstractItemModel
{
     Q_OBJECT
    friend class DAO;

public:
     TreeModel( QObject *parent = NULL);
     ~TreeModel();

     QVariant data(const QModelIndex &index, int role) const;
     Qt::ItemFlags flags(const QModelIndex &index) const;
     QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
     QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
     QModelIndex parent(const QModelIndex &index) const;
     int rowCount(const QModelIndex &parent = QModelIndex()) const;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;

     void insertChild(QModelIndex& index);
     void deleteItem(QModelIndex& index);


     TreeItem* GetItemByIndex(QModelIndex &index);

 private:
     void setupModelData(const QStringList &lines, TreeItem *parent);

     TreeHeaderItem *rootItem;

     // QAbstractItemModel interface
public:
     virtual bool setData(const QModelIndex& index, const QVariant& value, int role);
};

#endif // TREEMODEL_H
