#ifndef SAXXML_H
#define SAXXML_H

#include <QMainWindow>
#include <QtXml>
#include <QTreeWidget>
namespace Ui {
class SaxXml;
}

class SaxXml : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaxXml(QWidget *parent = nullptr);
    ~SaxXml();

    void ReadXml(QDomNode& docNode, QTreeWidgetItem * pItem,int n=0);
private slots:
    void OpenFile();
private:
    Ui::SaxXml *ui;
    int m_nCount;
};

#endif // SAXXML_H
