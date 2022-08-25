#include "domxml.h"
#include "ui_domxml.h"
#include <QFile>

DomXml::DomXml(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DomXml)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    //ReadXml();
    WriteXml();
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

void DomXml::WriteXml()
{
    QDomDocument doc;
    QDomElement root,child1,child2;
    QStringList elemList,attrList;
    QDomProcessingInstruction ins=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(ins);
    elemList<<"menu"<<"";
    CreatNode(doc,root,elemList);
    elemList.clear();
    elemList<<"open"<<"";
    attrList<<"num"<<"1"<<"order"<<"4134";
    CreatNode(doc,child1,elemList,attrList);
    root.appendChild(child1);
    elemList.clear();
    attrList.clear();
    elemList<<"tip"<<"open files";
    CreatNode(doc,child2,elemList);
    child1.appendChild(child2);
    elemList.clear();
    elemList<<"key"<<"ctrl+o";
    CreatNode(doc,child2,elemList);
    child1.appendChild(child2);

    elemList.clear();
    attrList.clear();
    elemList<<"save"<<"";
    attrList<<"num"<<"2"<<"order"<<"152";
    CreatNode(doc,child1,elemList,attrList);
    elemList.clear();
    elemList<<"tip"<<"save files";
    CreatNode(doc,child2,elemList);
    child1.appendChild(child2);
    elemList.clear();
    elemList<<"key"<<"ctrl+s";
    CreatNode(doc,child2,elemList);
    child1.appendChild(child2);
    root.appendChild(child1);
    doc.appendChild(root);
//    QDomAttr num=doc.createAttribute("num");
//    num.setValue("1");
//    QDomText text=doc.createTextNode("open files");
//    QDomElement tip=doc.createElement("tip");
//    tip.appendChild(text);
//    text=doc.createTextNode("ctrl+o");
//    QDomElement key=doc.createElement("key");
//    key.appendChild(text);

//    QDomElement action=doc.createElement("open");
//    action.setAttributeNode(num);
//    action.appendChild(tip);
//    action.appendChild(key);
//    root.appendChild(action);

    QFile file("write.xml");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

void DomXml::CreatNode(QDomDocument &doc,QDomElement &child, QStringList elemList, QStringList attrList)
{
    child=doc.createElement(elemList.at(0));
    if(!elemList.at(1).isEmpty())
    {
        QDomText text=doc.createTextNode(elemList.at(1));
        child.appendChild(text);
    }
    QDomAttr attr;
    for (int i=0;i<attrList.size();i+=2) {
        attr=doc.createAttribute(attrList.at(i));
        attr.setValue(attrList.at(i+1));
        child.setAttributeNode(attr);
    }
}
