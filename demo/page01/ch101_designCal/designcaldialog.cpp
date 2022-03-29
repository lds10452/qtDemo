#include "designcaldialog.h"
#include "ui_designcaldialog.h"
#include <QRegExpValidator>
const static double PI= 3.14159;
designCalDialog::designCalDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::designCalDialog)
{
    ui->setupUi(this);
    QRegExp regExp("[1-9]+[0-9]*");
    ui->radiusLineEdit->setValidator(new QRegExpValidator(regExp,this));
}

designCalDialog::~designCalDialog()
{
    delete ui;
}

void designCalDialog::on_countBtn_clicked()
{
    bool ok;
    QString areaStr;
    QString valueStr=ui->radiusLineEdit->text();
    int valueInt=valueStr.toInt(&ok);
    double areaInt=valueInt*valueInt*PI;
    ui->areaLabel_2->setText(areaStr.setNum(areaInt));
}

void designCalDialog::on_radiusLineEdit_textEdited(const QString &arg1)
{
    ui->countBtn->setEnabled(ui->radiusLineEdit->hasAcceptableInput());
}
