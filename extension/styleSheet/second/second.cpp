#include "second.h"
#include "ui_second.h"

second::second(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    setStyleSheet("QGroupBox{color:green;} QPushButton{color:red;}");
}

second::~second()
{
    delete ui;
}
