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
private:
    Ui::DomXml *ui;
};

#endif // DOMXML_H
