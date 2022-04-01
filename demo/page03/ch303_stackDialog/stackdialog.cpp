#include "stackdialog.h"
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
StackDialog::StackDialog(QWidget *p):QDialog(p)
{
    QListWidget *list=new QListWidget;
    list->insertItem(0,tr("window1"));
    list->insertItem(1,tr("window2"));
    list->insertItem(2,tr("window2"));
    QLabel *label1=new QLabel(tr("label1"));
    QLabel *label2=new QLabel(tr("label2"));
    QLabel *label3=new QLabel(tr("label3"));
    QStackedWidget *stack=new QStackedWidget;
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);
    QHBoxLayout *lay=new QHBoxLayout(this);
    lay->setMargin(5);
    lay->setSpacing(5);
    lay->addWidget(list);
    lay->addWidget(stack,0,Qt::AlignHCenter);
    lay->setStretchFactor(list,1);
    lay->setStretchFactor(stack,3);
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
}
