#include "domxml.h"
#include "ui_domxml.h"
#include <QFile>

DomXml::DomXml(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DomXml)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    ReadXml();
}

DomXml::~DomXml()
{
    delete ui;
}

void DomXml::ReadXml()
{
    QFile file(":/res/menu.xml");
    if(!file.open(QIODevice::ReadOnly)) return;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomNode firstNode=doc.firstChild();
    qDebug()<<qPrintable(firstNode.nodeName())
           <<qPrintable(firstNode.nodeValue());

    QDomElement docElem=doc.documentElement();
    PrintfInfo(docElem);
}

void DomXml::PrintfInfo(QDomElement e)
{
    qDebug()<<e.tagName();
    if(e.hasAttribute("编号"))
    {
        qDebug()<<"编号:"<<e.attribute("编号");
    }
    QDomNodeList list=e.childNodes();
    //qDebug()<<"list size:"<<list.size();
    for(int i=0;i<list.count();i++)
    {
        QDomNode node=list.at(i);
        if(node.isElement())
        {
            PrintfInfo(node.toElement());
        }
        else if (node.isCDATASection()) {
            qDebug()<<node.toCDATASection().data();
        }
        else if (node.isComment()) {
            qDebug()<<node.toComment().data();
        }
        else {
            qDebug()<<node.toText().data();
        }
    }
}
