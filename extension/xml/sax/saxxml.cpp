#include "saxxml.h"
#include "ui_saxxml.h"
#include <QFile>
#include <QLabel>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
SaxXml::SaxXml(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaxXml)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);

    ui->treeWidget->setStyleSheet("QTreeView::branch:open:has-children:!has-siblings,"
                                 "QTreeView::branch:open:has-children:has-siblings {image: url(:/res/expand.png);}"
                                 "QTreeView::branch:closed:has-children{image: url(:/res/treeHide.png);}"
                                 "QTreeview::item{width:250px;}"
                                  "QTreeWidget QLabel{color:red;}");
    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList()<<"书籍"<<"信息"<<"价格");
    ui->treeWidget->setColumnWidth(0,150);
    ui->treeWidget->setColumnWidth(1,150);

    QFile file(":/res/menu.xml");
    if(file.open(QIODevice::ReadOnly))
    {
        QDomDocument dom("WCM");
        if (dom.setContent(&file))
        {
            ui->treeWidget->clear();
            QDomElement docElem = dom.documentElement();
            ReadXml(docElem, NULL);
            ui->treeWidget->expandAll();
        }
    }
    file.close();

    QMenu *menu=this->menuBar()->addMenu("file");
    QAction *openAction=new QAction("open");
    connect(openAction,&QAction::triggered,this,&SaxXml::OpenFile);
    menu->addAction(openAction);
}

SaxXml::~SaxXml()
{
    delete ui;
}

void SaxXml::ReadXml(QDomNode &docNode, QTreeWidgetItem *pItem,int n)
{
    QTreeWidgetItem *item=NULL;
    if(docNode.nodeType()!=QDomNode::TextNode)
    {
        if( pItem )
        {
            item = new QTreeWidgetItem(pItem);
        }
        else {
            item=new QTreeWidgetItem(ui->treeWidget);
        }
    }
    if(docNode.isElement())
    {
        QDomElement elem=docNode.toElement();
        item->setIcon(0,n==0?QIcon(":/res/red.png"):(n==1?QIcon(":/res/green.png"):QIcon(":/res/blue.png")));
        item->setText(0, elem.tagName());
        item->setTextAlignment(1,Qt::AlignCenter);
        if(elem.hasAttribute("价格"))
        {
            item->setText(2,elem.attribute("价格"));
        }
        if( pItem )
        {
            pItem->addChild(item);
        }
        else
        {
            ui->treeWidget->addTopLevelItem(item);
        }
    }
    else if(docNode.nodeType()==QDomNode::TextNode)
    {
        pItem->setText (1,docNode.toText().data());
    }
    else if(docNode.nodeType()==QDomNode::CDATASectionNode)
    {
        QLabel *label=new QLabel(ui->treeWidget);
        label->setText(docNode.toCDATASection().data());
        ui->treeWidget->setItemWidget(item,0,label);
    }
    else if (docNode.isComment())
    {
        QLabel *label=new QLabel(ui->treeWidget);
        label->setText(docNode.toComment().data());
        ui->treeWidget->setItemWidget(item,0,label);
    }
    QDomNodeList list=docNode.childNodes();
    for (int i=0;i<list.size();i++)
    {
        QDomNode node=list.at(i);
        ReadXml(node, item,n+1);
    }
}

void SaxXml::OpenFile()
{
    QString filePath=QFileDialog::getOpenFileName(this,"open file","../xml/res/","xml file(*.xml)");
//    int pos=filePath.lastIndexOf("/");
//    QString fileName=filePath.right(filePath.length()-pos-1);
//    QFile file(":/res/"+fileName);
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly))
    {
        ui->treeWidget->clear();
        QDomDocument dom("WCM");
        if (dom.setContent(&file))
        {
            ui->treeWidget->clear();
            QDomElement docElem = dom.documentElement();
            ReadXml(docElem, NULL);
            ui->treeWidget->expandAll();
        }
    }
    file.close();
}
