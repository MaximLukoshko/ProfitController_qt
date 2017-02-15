#ifndef MENUFLAGS_H
#define MENUFLAGS_H
#pragma once
#include "qglobal.h"

enum MenuFlag {
    MF_NoMenuFlags = 0,
    MF_AddMenuVisible = 1,
    MF_AddMenuDisabled = 2,
    MF_DeleteMenuVisible = 4,
    MF_DeleteMenuDisabled = 8,
};

Q_DECLARE_FLAGS(MenuFlags, MenuFlag)

#endif // MENUFLAGS_H
