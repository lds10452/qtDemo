#include "widget.h"
#include "ui_widget.h"
#include "first/first.h"
#include "second/second.h"
#include "third/third.h"
#include "selector/selector.h"
#include "fakeStatus/fakestatus.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->firstPushButton,&QPushButton::clicked,this,&Widget::firstButtonClicked);
    connect(ui->secPushButton,&QPushButton::clicked,this,&Widget::secButtonClicked);
    connect(ui->thirdPushButton,&QPushButton::clicked,this,&Widget::thirdButtonClicked);
    connect(ui->selPushButton,&QPushButton::clicked,this,&Widget::selectButtonClciked);
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::fakeStatusClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::firstButtonClicked()
{
    first *w=new first(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

void Widget::secButtonClicked()
{
    second *w=new second(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

void Widget::thirdButtonClicked()
{
    third *w=new third(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

void Widget::selectButtonClciked()
{
    selector *w=new selector(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

void Widget::fakeStatusClicked()
{
    fakeStatus *w=new fakeStatus(this);
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

