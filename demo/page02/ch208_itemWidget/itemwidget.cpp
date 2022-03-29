#include "itemwidget.h"
#include "ui_itemwidget.h"

ItemWidget::ItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemWidget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(treeItemChanged(QTreeWidgetItem*)));

}

ItemWidget::~ItemWidget()
{
    delete ui;
}

void ItemWidget::init()
{
    ui->treeWidget->clear();
    QTreeWidgetItem *group1=new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0,"group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem11=new QTreeWidgetItem(group1);
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem11->setText(0,"subItem1");
    subItem11->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem12=new QTreeWidgetItem(group1);
    subItem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem12->setText(0,"subItem2");
    subItem12->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem111=new QTreeWidgetItem(subItem11);
    subItem111->setText(0,"subItem111");
    subItem111->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem111->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem112=new QTreeWidgetItem(subItem11);
    subItem112->setText(0,"subItem112");
    subItem112->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem112->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *group2=new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0,"group2");
    group2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group2->setCheckState(0,Qt::Checked);
    QTreeWidgetItem *subItem21=new QTreeWidgetItem(group2);
    subItem21->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem21->setText(0,"subItem3");
    subItem21->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem22=new QTreeWidgetItem(group2);
    subItem22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem22->setText(0,"subItem4");
    subItem22->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem211=new QTreeWidgetItem(subItem21);
    subItem211->setText(0,"subItem211");
    subItem211->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem211->setCheckState(0,Qt::Unchecked);
    QTreeWidgetItem *subItem212=new QTreeWidgetItem(subItem21);
    subItem212->setText(0,"subItem212");
    subItem212->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem212->setCheckState(0,Qt::Unchecked);

    treeItemChanged(group1);
    treeItemChanged(group2);
}

void ItemWidget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent=item->parent();
    if(!parent)
    {
        return;
    }
    int selectedCount=0;
    int childCount=parent->childCount();
    for (int i=0;i<childCount;i++) {
        QTreeWidgetItem *childItem=parent->child(i);
        if(Qt::Checked==childItem->checkState(0)|Qt::PartiallyChecked==childItem->checkState(0))
        {
            selectedCount++;
        }
    }
    if(selectedCount<=0)
    {
        parent->setCheckState(0,Qt::Unchecked);
    }
    else if (selectedCount>0&&selectedCount<childCount) {
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if (selectedCount==childCount) {
        parent->setCheckState(0,Qt::Checked);
    }
    QTreeWidgetItem *preParent=parent->parent();
    if(!preParent)
    {
        return;
    }
    updateParentItem(parent);
}

void ItemWidget::treeItemChanged(QTreeWidgetItem *item)
{
    QString itemText=item->text(0);
    int count=item->childCount();
    if(Qt::Checked==item->checkState(0))
    {
        if(count>0)
        {
            for (int i=0;i<count;i++) {
                item->child(i)->setCheckState(0,Qt::Checked);
                treeItemChanged(item->child(i));
            }
        }
        else {
            updateParentItem(item);
        }
    }
    else if (Qt::Unchecked==item->checkState(0)) {
        if(count>0)
        {
            for (int i=0;i<count;i++) {
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else {
            updateParentItem(item);
        }
    }
}
