#include "third.h"
#include "ui_third.h"
#include <QFile>
third::third(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::third)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    QFile file(":/res/myStyle.qss");
    if(file.open(QFile::ReadOnly))
    {
        QString str=QString(file.readAll());
        setStyleSheet(str);
        file.close();
    }
    m_bFlag=true;
    connect(ui->pushButton,&QPushButton::clicked,this,&third::OnPushButtonClicked);
}

third::~third()
{
    delete ui;
}

void third::OnPushButtonClicked()
{
    QFile file;
    if(m_bFlag)
        file.setFileName(":/res/myStyle2.qss");
    else
        file.setFileName(":/res/myStyle.qss");
    m_bFlag=!m_bFlag;
    if(file.open(QFile::ReadOnly))
    {
        QString str=QString(file.readAll());
        setStyleSheet(str);
        file.close();
    }
}
