#include "execthreaddialog.h"
#include "../ch1201_threadDlg/threaddialog.h"
#include "../ch1202_SemaphoreDlg/semaphoredialog.h"
#include "../ch1203_WaitConditionDlg/waitconditiondialog.h"
#include "../ch1204_TimeServer/timedialog.h"
#include "../ch1205_TimeClient/timeclient.h"
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
    connect(btn4,&QPushButton::clicked,this,&ExecThreadDialog::TimeServer);
    connect(btn5,&QPushButton::clicked,this,&ExecThreadDialog::Time2Client);
    QHBoxLayout *hLayout1=new QHBoxLayout;
    hLayout1->addWidget(btn1);
    hLayout1->addWidget(btn2);
    hLayout1->addWidget(btn3);
    QHBoxLayout *hLayout2=new QHBoxLayout;
    hLayout2->addStretch(1);
    hLayout2->addWidget(btn4);
    hLayout2->addWidget(btn5);
    hLayout2->addStretch(1);
    QVBoxLayout *vLayout=new QVBoxLayout(this);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
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

void ExecThreadDialog::TimeServer()
{
    TimeDialog *w=new TimeDialog(this);
    w->show();
}

void ExecThreadDialog::Time2Client()
{
    TimeClient *w=new TimeClient(this);
    w->show();
}
