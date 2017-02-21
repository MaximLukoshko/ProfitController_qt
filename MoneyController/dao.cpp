#include "dao.h"

DAO::DAO()
{
}

bool DAO::SaveModel(TreeModel* model)
{
    Q_UNUSED(model);
    return true;
}

bool DAO::LoadModel(TreeModel* model)
{
    Q_UNUSED(model);
    TreeHeaderItem* rootItem = new TreeHeaderItem();

    rootItem->appendNewChild();
    rootItem->appendNewChild();

    for (int var = 0; var < 12; ++var)
        rootItem->child(0)->appendNewChild();


    rootItem->child(1)->appendNewChild();
    rootItem->child(1)->child(0)->appendNewChild();

    model->rootItem=rootItem;

    return true;
}
