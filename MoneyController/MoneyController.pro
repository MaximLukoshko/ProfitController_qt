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
    treeview.cpp

HEADERS  += mainwindow.h \
    treemodel.h \
    treeitem.h \
    Column.h \
    treeview.h

FORMS    += mainwindow.ui

OTHER_FILES +=
