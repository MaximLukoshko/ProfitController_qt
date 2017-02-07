#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QTreeView>
#include <treemodel.h>
#include <QWidget>

class TreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit TreeView(QWidget *parent = 0);

protected:
    TreeModel* GetModel();

signals:

private slots:
    void onCustomMenuSelected(const QPoint &pos);
    void on_add_child();
    void on_add_child_to_root();
    void on_delete_item();
};

#endif // TREEVIEW_H
