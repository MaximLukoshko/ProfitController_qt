#include "treeview.h"
#include "treemodel.h"
#include <QMenu>

TreeView::TreeView(QWidget *parent) :
    QTreeView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this, SIGNAL(customContextMenuRequested(QPoint)),SLOT(onCustomMenuSelected(QPoint)));
}

TreeModel* TreeView::GetModel()
{
    return dynamic_cast<TreeModel*>(model());
}

void TreeView::onCustomMenuSelected(const QPoint &pos)
{
    QMenu menu(this);

    QModelIndex index = indexAt(pos);
    bool local = index.isValid() ? true : false;

    QAction* addAct = new QAction("Добавить", this);
    menu.addAction(addAct);

    if( local )
    {
        connect(addAct, SIGNAL(triggered()),SLOT(on_add_child()));
        QAction* deleteAct = new QAction("Удалить", this);
        connect(deleteAct, SIGNAL(triggered()),SLOT(on_delete_item()));
        menu.addAction(deleteAct);
    }
    else
    {
        connect(addAct, SIGNAL(triggered()),SLOT(on_add_child_to_root()));
    }

    menu.exec(QCursor::pos());
}

void TreeView::on_add_child()
{
    QModelIndex index = currentIndex();
    GetModel()->insertChild(index);
    this->expand(index);
}

void TreeView::on_add_child_to_root()
{
    QModelIndex empty_index;
    GetModel()->insertChild(empty_index);
}

void TreeView::on_delete_item()
{
    QModelIndex index = currentIndex();
    GetModel()->deleteItem(index);
}
