#include "networkdialog.h"
#include <qpushbutton.h>
#include <QGridLayout>
#include "../ch1001_networkInformation/networkinfowgt.h"
#include "../ch1002_udpServer/udpserverdialog.h"
#include "../ch1003_udpClient/udpclientdialog.h"
#include "../ch1004_tcpServer/tcpdialog.h"
#include "../ch1005_tcpClient/tcpclient.h"
#include "../ch1006_http/httpmainwindow.h"
NetWorkDialog::NetWorkDialog()
{
    QPushButton *networkInfo=new QPushButton("network information");
    connect(networkInfo,&QPushButton::clicked,this,&NetWorkDialog::ShowNetworkInfo);
    QPushButton *udpServer=new QPushButton("udpServer");
    connect(udpServer,&QPushButton::clicked,this,&NetWorkDialog::ShowUdpServer);
    QPushButton *udpClient=new QPushButton("nudpClient");
    connect(udpClient,&QPushButton::clicked,this,&NetWorkDialog::SHowUdpClient);
    QPushButton *tcpServer=new QPushButton("tcpServer");
    connect(tcpServer,&QPushButton::clicked,this,&NetWorkDialog::ShowTcpServer);
    QPushButton *tcpClient=new QPushButton("tcpClient");
    connect(tcpClient,&QPushButton::clicked,this,&NetWorkDialog::ShowTcpClient);
    QPushButton *http=new QPushButton("http");
    connect(http,&QPushButton::clicked,this,&NetWorkDialog::ShowHttp);

    QGridLayout *layout=new QGridLayout(this);
    layout->addWidget(networkInfo,0,0);
    layout->addWidget(http,0,1);
    layout->addWidget(udpServer,1,0);
    layout->addWidget(udpClient,1,1);
    layout->addWidget(tcpServer,2,0);
    layout->addWidget(tcpClient,2,1);
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

void NetWorkDialog::ShowTcpServer()
{
    TcpDialog *w=new TcpDialog(this);
    w->show();
}
void NetWorkDialog::ShowTcpClient()
{
    TcpClient *w=new TcpClient(this);
    w->show();
}

void NetWorkDialog::ShowHttp()
{
    HttpMainWindow *w=new HttpMainWindow;
    w->setWindowModality(Qt::WindowModal);
    w->show();
}
