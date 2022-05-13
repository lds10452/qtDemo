#include "networkdialog.h"
#include <qpushbutton.h>
#include <QGridLayout>
#include "../ch1001_networkInformation/networkinfowgt.h"
#include "../ch1002_udpServer/udpserverdialog.h"
#include "../ch1003_udpClient/udpclientdialog.h"
NetWorkDialog::NetWorkDialog()
{
    QPushButton *networkInfo=new QPushButton("network information");
    connect(networkInfo,&QPushButton::clicked,this,&NetWorkDialog::ShowNetworkInfo);
    QPushButton *udpServer=new QPushButton("udpServer");
    connect(udpServer,&QPushButton::clicked,this,&NetWorkDialog::ShowUdpServer);
    QPushButton *udpClient=new QPushButton("nudpClient");
    connect(udpClient,&QPushButton::clicked,this,&NetWorkDialog::SHowUdpClient);
    QGridLayout *layout=new QGridLayout(this);
    layout->addWidget(networkInfo,0,0);
    layout->addWidget(udpServer,1,0);
    layout->addWidget(udpClient,1,1);
}

void NetWorkDialog::ShowNetworkInfo()
{
    NetWorkInfoWgt *w=new NetWorkInfoWgt;
    w->setWindowModality(Qt::WindowModal);
    w->show();
}

void NetWorkDialog::ShowUdpServer()
{
    UdpServerDialog *w=new UdpServerDialog(this);
    w->show();
}

void NetWorkDialog::SHowUdpClient()
{
    UdpClientDialog *w=new UdpClientDialog(this);
    w->show();
}
