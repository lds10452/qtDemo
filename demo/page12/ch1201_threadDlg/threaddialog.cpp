#include "threaddialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "workthread.h"
ThreadDialog::ThreadDialog()
{
    btn1=new QPushButton("start");
    btn2=new QPushButton("stop");
    btn2->setEnabled(false);
    btn3=new QPushButton("exit");
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    connect(btn1,&QPushButton::clicked,this,&ThreadDialog::slotStart);
    connect(btn2,&QPushButton::clicked,this,&ThreadDialog::slotStop);
    connect(btn3,&QPushButton::clicked,this,&QDialog::close);

    for (int i=0;i<MAXSIZE;i++) {
        workThread[i]=new WorkThread;
    }
}

void ThreadDialog::slotStart()
{
    for (int i=0;i<MAXSIZE;i++) {
        workThread[i]->start();
    }
    btn1->setEnabled(false);
    btn2->setEnabled(true);
}

void ThreadDialog::slotStop()
{
    for (int i=0;i<MAXSIZE;i++) {
        workThread[i]->terminate();
        workThread[i]->wait();
    }
    btn1->setEnabled(true);
    btn2->setEnabled(false);
}


