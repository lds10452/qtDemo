#include "dialog.h"
#include "ui_dialog.h"
#include "dom/domxml.h"
#include "sax/saxxml.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    DomXml *w=new DomXml(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

void Dialog::on_pushButton_2_clicked()
{
    SaxXml *w=new SaxXml(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}
