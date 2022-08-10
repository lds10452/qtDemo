#include "selector.h"
#include "ui_selector.h"
#include <QButtonGroup>
selector::selector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selector)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    setStyleSheet(StyleSheetString(0));
    QButtonGroup *group=new QButtonGroup(this);
    group->addButton(ui->pushButton,0);
    group->addButton(ui->pushButton_2,1);
    group->addButton(ui->pushButton_3,2);
    group->addButton(ui->pushButton_4,3);
    group->addButton(ui->pushButton_5,4);
    group->addButton(ui->pushButton_6,5);
    group->addButton(ui->pushButton_7,6);
    group->setExclusive(true);
    connect(group,SIGNAL(buttonClicked(int)),this,SLOT(ButtonClicked(int)));
}

selector::~selector()
{
    delete ui;
}

QString selector::StyleSheetString(int index)
{
    static const char *stringList[]={
        "*{background-color:rgb(50,150,50); color:red; border-raidus:5px;}",
        "QFrame{background-color:rgb(250,120,0); border:3px solid;}",
        ".QFrame{background-color:rgb(20,120,250); border:2px solid;}",
        "QLabel[text=\"label\"]{background-color:rgb(220,120,250); color:green;}",
        "QLabel#label{background-color:rgb(220,120,250); color:green;}",
        "QFrame>QLabel{background-color:rgb(120,120,150); color:blue;}",
        "QFrame QLabel{background-color:rgb(220,120,150); color:red;}"
    };
    return stringList[index];
}

void selector::ButtonClicked(int index)
{
    setStyleSheet(StyleSheetString(index));
}
