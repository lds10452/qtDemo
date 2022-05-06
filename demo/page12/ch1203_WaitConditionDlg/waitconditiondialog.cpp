#include "waitconditiondialog.h"
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
const int DataSize=1000;
const int buffSize=80;
int buff[buffSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUseBytes=0;
int rIndex=0;
WaitConditionDialog::WaitConditionDialog()
{
    QPushButton *btn=new QPushButton("start");
    connect(btn,&QPushButton::clicked,this,&WaitConditionDialog::slotStart);
    QHBoxLayout *lyout=new QHBoxLayout(this);
    lyout->addWidget(btn);
}

void WaitConditionDialog::slotStart()
{
    ProducerA producer;
    ConsumerA consumerA;
    ConsumerA consumerB;
    producer.start();
    consumerA.start();
    consumerB.start();
    producer.wait();
    consumerA.wait();
    consumerB.wait();
}

void ProducerA::run()
{
    for(int i=0;i<DataSize;i++)
    {
        mutex.lock();
        if(numUseBytes==buffSize)
            bufferEmpty.wait(&mutex);
        buff[i%buffSize]=i;
        ++numUseBytes;
        bufferFull.wakeAll();
        mutex.unlock();
    }
}

void ConsumerA::run()
{
    forever{
        mutex.lock();
        if(numUseBytes==0)
            bufferFull.wait(&mutex);
        qDebug()<<currentThreadId()<<" "<<rIndex<<" "<<buff[rIndex];
        rIndex=(++rIndex)%buffSize;
        --numUseBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
    }
}
