#-------------------------------------------------
#
# Project created by QtCreator 2017-01-29T19:37:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MoneyController
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treemodel.cpp \
    treeitem.cpp \
    treeview.cpp \
    treeyearitem.cpp \
    treemonthitem.cpp \
    treeorderitem.cpp \
    treeheaderitem.cpp

HEADERS  += mainwindow.h \
    treemodel.h \
    treeitem.h \
    Column.h \
    treeview.h \
    treeyearitem.h \
    treemonthitem.h \
    treeorderitem.h \
    treeheaderitem.h \
    Month.h \
    MenuFlags.h

FORMS    += mainwindow.ui

OTHER_FILES +=
