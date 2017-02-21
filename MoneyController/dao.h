#ifndef DAO_H
#define DAO_H

#include "treemodel.h"

class TreeModel;

class DAO
{
public:
    DAO();

    static bool SaveModel(TreeModel* model);
    static bool LoadModel(TreeModel* model);
};

#endif // DAO_H
