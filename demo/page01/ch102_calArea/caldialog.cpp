#include "caldialog.h"
#include <QGridLayout>
#define PI 3.14159
calDialog::calDialog(QWidget *parent) : QWidget(parent)
{
    label1=new QLabel("radius:",this);
    lineEdit=new QLineEdit(this);
    label2=new QLabel(this);
    button=new QPushButton(this);
    button->setText(tr("show area"));
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);

    //label1->setBuddy(label2);
    connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea()));
}

void calDialog::showArea()
{
    QString str;
    QString radiusStr=lineEdit->text();
    int radiusInt=radiusStr.toInt();
    double area=radiusInt*radiusInt*PI;
    label2->setText(str.setNum(area));
}
