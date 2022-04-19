#include "viewexmainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QTableView>
#include <QSplitter>
#include <QFileDialog>
#include <QTextStream>
#include "histogramview.h"
ViewExMainWindow::ViewExMainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(600,600);
    createMenu();
    setupModelView();
}

void ViewExMainWindow::createMenu()
{
    QMenu *menu=menuBar()->addMenu("file");
    QAction *open=new QAction("open",this);
    menu->addAction(open);
    connect(open,SIGNAL(triggered()),this,SLOT(openFile()));
}

void ViewExMainWindow::setupModelView()
{
    model=new QStandardItemModel(4,4,this);
    model->setHeaderData(0,Qt::Horizontal,tr("部门"));
    model->setHeaderData(1,Qt::Horizontal,tr("男"));
    model->setHeaderData(2,Qt::Horizontal,tr("女"));
    model->setHeaderData(3,Qt::Horizontal,tr("退休"));
    QTableView *view=new QTableView;
    view->setModel(model);
    HistogramView *hView=new HistogramView;
    hView->setModel(model);
    QItemSelectionModel *selectionModel=new QItemSelectionModel(model);
    view->setSelectionModel(selectionModel);
    hView->setSelectionModel(selectionModel);
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),view,SLOT(selectionChanged(QItemSelection,QItemSelection)));
    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),hView,SLOT(selectionChanged(QItemSelection,QItemSelection)));
    QSplitter *splitter=new QSplitter;
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(view);
    splitter->addWidget(hView);
    setCentralWidget(splitter);
}

void ViewExMainWindow::openFile()
{
    QString name=QFileDialog::getOpenFileName(this,"open file","../demo/res/text/","files(*.txt)");
    if(!name.isEmpty())
    {
        QFile file(name);
        if(file.open(QFile::ReadOnly|QFile::Text))
        {
            QTextStream stream(&file);
            QString line;
            model->removeRows(0,model->rowCount(QModelIndex()),
                  QModelIndex());
            int row = 0;
            do
            {
                line = stream.readLine();
                if (!line.isEmpty())
                {
                       model->insertRows(row, 1, QModelIndex());
                       QStringList pieces = line.split(",", QString
                           ::SkipEmptyParts);
                       model->setData(model->index(row, 0, QModelIndex()),
                           pieces.value(0));
                       model->setData(model->index(row, 1, QModelIndex()),
                           pieces.value(1));
                       model->setData(model->index(row, 2, QModelIndex()),
                           pieces.value(2));
                       model->setData(model->index(row,3, QModelIndex()),
                           pieces.value(3));
                       row++;
                }
            } while (!line.isEmpty());
          file.close();
        }
    }
}
