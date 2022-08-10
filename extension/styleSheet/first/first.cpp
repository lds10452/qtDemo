#include "first.h"
#include "ui_first.h"

first::first(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::first)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
}

first::~first()
{
    delete ui;
}
