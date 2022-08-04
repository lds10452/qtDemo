#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->qBattery->setPowerLevel(value);
}

void Widget::on_qBattery_powerLevelChanged(int arg1)
{
    QString str=QString("当前电量:%1%").arg(arg1);
    ui->label->setText(str);
}
