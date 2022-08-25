#ifndef DOMXML_H
#define DOMXML_H

#include <QWidget>
#include <QtXml>

namespace Ui {
class DomXml;
}

class DomXml : public QWidget
{
    Q_OBJECT

public:
    explicit DomXml(QWidget *parent = nullptr);
    ~DomXml();

    void ReadXml();
    void PrintfInfo(QDomElement e);
    void WriteXml();
    void CreatNode(QDomDocument &doc,QDomElement &child,QStringList elemList,QStringList attrList=QStringList());
private:
    Ui::DomXml *ui;
};

#endif // DOMXML_H
