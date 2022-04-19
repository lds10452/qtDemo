#include "delegatedialog.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QTextStream>
#include "datedelegate.h"
#include "spindelegate.h"
#include "comboxdelegate.h"
#include <QHBoxLayout>
DelegateDialog::DelegateDialog()
{
    resize(600,300);
    QStandardItemModel *model=new QStandardItemModel(4,4);
    QTableView *tableView=new QTableView;
    tableView->setModel(model);
    DateDelegate *dateDelegate=new DateDelegate;
    tableView->setItemDelegateForColumn(1,dateDelegate);
    ComboxDelegate *comboDelegate=new ComboxDelegate;
    tableView->setItemDelegateForColumn(2,comboDelegate);
    SpinDelegate *spinDelegate=new SpinDelegate;
    tableView->setItemDelegateForColumn(3,spinDelegate);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("姓名"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("生日"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("职业"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("收入"));
    QFile file("../demo/res/text/test.txt");
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream stream(&file);
        model->removeRows(0,model->rowCount(QModelIndex()),QModelIndex());
        QString line;
        int row=0;
        do {
            line=stream.readLine();
            if(!line.isEmpty())
            {
                model->insertRows(row,1,QModelIndex());
                QStringList pieces=line.split(",",QString::SkipEmptyParts);
                model->setData(model->index(row,0,QModelIndex()),pieces.value(0));
                model->setData(model->index(row,1,QModelIndex()),pieces.value(1));
                model->setData(model->index(row,2,QModelIndex()),pieces.value(2));
                model->setData(model->index(row,3,QModelIndex()),pieces.value(3));
                row++;
            }
        } while (!line.isEmpty());
        file.close();
    }
    QHBoxLayout *main=new QHBoxLayout(this);
    main->addWidget(tableView);
}
