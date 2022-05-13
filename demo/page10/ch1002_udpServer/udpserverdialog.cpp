#include "udpserverdialog.h"
#include <QVBoxLayout>
#include <QHostAddress>
UdpServerDialog::UdpServerDialog(QWidget*p):QDialog(p)
{
    timerLabel=new QLabel("timer:");
    textLineEdit=new QLineEdit;
    btn=new QPushButton("start");
    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->addWidget(timerLabel);
    layout->addWidget(textLineEdit);
    layout->addWidget(btn);
    connect(btn,&QPushButton::clicked,this,&UdpServerDialog::btnClicked);
    port=5555;
    isStarted=false;
    udpSocket=new QUdpSocket(this);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&UdpServerDialog::timeOut);
}

void UdpServerDialog::btnClicked()
{
    if(!isStarted)
    {
        btn->setText("stop");
        timer->start(1000);
        isStarted=true;
    }
    else {
        btn->setText("start");
        isStarted=false;
        timer->stop();
    }
}

void UdpServerDialog::timeOut()
{
    QString msg=textLineEdit->text();
    int length=0;
    if(msg=="")
    {
        return;
    }
    if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length())
    {
        return;
    }
}
