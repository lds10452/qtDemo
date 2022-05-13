#include "networkinfowgt.h"
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QMessageBox>
NetWorkInfoWgt::NetWorkInfoWgt(QWidget *parent) : QWidget(parent)
{
    QLabel *hostLabel=new QLabel("hostName:");
    hostLineEdit=new QLineEdit;
    QLabel *ipLabel=new QLabel("ip:");
    ipLineEdit=new QLineEdit;
    btn=new QPushButton("detail:");
    QGridLayout *layout=new QGridLayout(this);
    layout->addWidget(hostLabel,0,0);
    layout->addWidget(hostLineEdit,0,1);
    layout->addWidget(ipLabel,1,0);
    layout->addWidget(ipLineEdit,1,1);
    layout->addWidget(btn,2,0,1,2);
    ShowDeviceInfo();
    connect(btn,&QPushButton::clicked,this,&NetWorkInfoWgt::ShowDetial);
}

void NetWorkInfoWgt::ShowDeviceInfo()
{
    QString hostName=QHostInfo::localHostName();
    hostLineEdit->setText(hostName);
    QHostInfo hostInfo=QHostInfo::fromName(hostName);
    QList<QHostAddress> listAddress=hostInfo.addresses();
//    if(!listAddress.isEmpty())
//    {
//        ipLineEdit->setText(listAddress.at(2).toString());
//    }
}

void NetWorkInfoWgt::ShowDetial()
{
    QString detail="";
    QList<QNetworkInterface> list=QNetworkInterface::allInterfaces();
    for(int i=0;i<list.count();i++)
    {
        QNetworkInterface interface=list.at(i);
        detail=detail+"device:"+interface.name()+"\n";
        detail=detail+"hardware address:"+interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList=interface.addressEntries();
        for(int j=1;j<entryList.count();j++)
        {
            QNetworkAddressEntry entry=entryList.at(j);
            detail=detail+"\t"+"ip address:"+entry.ip().toString()+"\n";
            detail=detail+"\t"+"netmask:"+entry.netmask().toString()+"\n";
            detail=detail+"\t"+"broadcast address:"+entry.broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,"detail",detail);
}
