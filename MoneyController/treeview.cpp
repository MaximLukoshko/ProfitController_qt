#include "treeview.h"
#include "treemodel.h"
#include <QMenu>
#include "MenuFlags.h"

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

    TreeItem* item = GetModel()->GetItemByIndex(index);
    MenuFlags itemMenuFlags = item->menuFlags();

    if(itemMenuFlags==MF_NoMenuFlags)
        return;

    QAction* addAct = NULL;

    if( itemMenuFlags&MF_AddMenuVisible )
    {
        addAct = new QAction("Новый " + item->GetChildName(), this);

        if( local )
            connect(addAct, SIGNAL(triggered()),SLOT(on_add_child()));
        else
            connect(addAct, SIGNAL(triggered()),SLOT(on_add_child_to_root()));

        if(itemMenuFlags & MF_AddMenuDisabled)
            addAct->setEnabled( false );

        menu.addAction(addAct);
    }


    QAction* deleteAct = NULL;
    if( itemMenuFlags&MF_DeleteMenuVisible )
    {
        deleteAct = new QAction("Удалить", this);
        connect(deleteAct, SIGNAL(triggered()),SLOT(on_delete_item()));

        if(itemMenuFlags & MF_DeleteMenuDisabled)
            deleteAct->setEnabled( false );

        menu.addAction(deleteAct);
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
