#include "execthreaddialog.h"
#include "../ch1201_threadDlg/threaddialog.h"
#include "../ch1202_SemaphoreDlg/semaphoredialog.h"
#include "../ch1203_WaitConditionDlg/waitconditiondialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
ExecThreadDialog::ExecThreadDialog()
{
    QPushButton *btn1=new QPushButton("baseThread");
    QPushButton *btn2=new QPushButton("semaphore");
    QPushButton *btn3=new QPushButton("waitCondition");
    QPushButton *btn4=new QPushButton("timeServe");
    QPushButton *btn5=new QPushButton("timeClient");
    connect(btn1,&QPushButton::clicked,this,&ExecThreadDialog::BaseThread);
    connect(btn2,&QPushButton::clicked,this,&ExecThreadDialog::SemaphoreThread);
    connect(btn3,&QPushButton::clicked,this,&ExecThreadDialog::WaitCondition);
    QHBoxLayout *hLayout=new QHBoxLayout;
    hLayout->addWidget(btn1);
    hLayout->addWidget(btn2);
    hLayout->addWidget(btn3);
    QVBoxLayout *vLayout=new QVBoxLayout(this);
    vLayout->addLayout(hLayout);
}

void ExecThreadDialog::BaseThread()
{
    ThreadDialog *d=new ThreadDialog;
    d->setModal(Qt::WindowModal);
    d->show();
}

void ExecThreadDialog::SemaphoreThread()
{
    SemaphoreDialog *w=new SemaphoreDialog;
    w->setModal(Qt::WindowModal);
    w->show();
}

void ExecThreadDialog::WaitCondition()
{
    WaitConditionDialog *w=new WaitConditionDialog;
    w->setModal(Qt::WindowModal);
    w->show();
}
