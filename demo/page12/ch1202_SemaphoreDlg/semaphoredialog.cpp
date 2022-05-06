#include "semaphoredialog.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QSemaphore>
#include <stdio.h>
#include <QDebug>
const int dataSize=1000;
const int bufferSize=80;
int buffer[bufferSize];
QSemaphore freeBytes(bufferSize);
QSemaphore useBytes(0);
SemaphoreDialog::SemaphoreDialog()
{
    QPushButton *btn=new QPushButton("start");
    connect(btn,&QPushButton::clicked,this,&SemaphoreDialog::slotStart);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(btn);
}

void SemaphoreDialog::slotStart()
{
    Producter producer;
    Consumer consumer;
    producer.start();
    consumer.start();
    producer.wait();
    consumer.wait();
}

void Consumer::run()
{
    for(int i=0;i<dataSize;i++)
    {
        useBytes.acquire();
        qDebug()<<buffer[i%bufferSize];
        if(i%16==0&&i!=0)
            qDebug()<<"\n";
        freeBytes.release();
    }
}

void Producter::run()
{
    for(int i=0;i<dataSize;i++)
    {
        freeBytes.acquire();
        buffer[i%bufferSize]=i%bufferSize;
        useBytes.release();
    }
}
