#include "fakestatus.h"
#include "ui_fakestatus.h"

fakeStatus::fakeStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fakeStatus)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    QString str="QPushButton{min-width:200px; min-height:170px;"//background-image: url(:/res/icon.png);
            "border:2px solid red;border-radius:20px;}"
            "QPushButton::hover{background-color:green}"
            "QPushButton::pressed{background-color:blue}"
            ;
    setStyleSheet(str);
}

fakeStatus::~fakeStatus()
{
    delete ui;
}
