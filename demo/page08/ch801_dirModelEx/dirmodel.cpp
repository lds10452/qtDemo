#include "dirmodel.h"
#include <QAbstractItemModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QHBoxLayout>
DirModel::DirModel(QWidget *parent) : QWidget(parent)
{
    QDirModel *model=new QDirModel;
    QTreeView *tree=new QTreeView;
    QListView *list=new QListView;
    QTableView *table=new QTableView;
    tree->setModel(model);
    list->setModel(model);
    table->setModel(model);
    tree->setSelectionMode(QAbstractItemView::MultiSelection);
    list->setSelectionModel(tree->selectionModel());
    table->setSelectionModel(tree->selectionModel());
    connect(tree,SIGNAL(doubleClicked(QModelIndex)),list,SLOT(setRootIndex(QModelIndex)));
    connect(tree,SIGNAL(doubleClicked(QModelIndex)),table,SLOT(setRootIndex(QModelIndex)));
    QSplitter *splitter=new QSplitter(this);
    splitter->addWidget(tree);
    splitter->addWidget(list);
    splitter->addWidget(table);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(splitter);
    this->setLayout(layout);
}
