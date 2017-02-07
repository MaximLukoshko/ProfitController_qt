#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "treemodel.h"
#include "treeview.h"
#include <QStandardItemModel>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->actionOpen,SIGNAL(triggered()),SLOT(close()));

    TreeView* treeView = new TreeView(ui->centralWidget);

    TreeModel* model = new TreeModel();
    treeView->setModel(model);

    ui->gridLayout->addWidget(treeView, 0, 0, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


