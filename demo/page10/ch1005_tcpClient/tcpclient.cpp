#include "tcpclient.h"
#include <QMessageBox>
TcpClient::TcpClient(QWidget*p):QDialog(p)
{
    setWindowTitle("client");
    content=new QListWidget;
    sendLineEdit=new QLineEdit;
    sendBtn=new QPushButton("send");
    userNameLabel=new QLabel("userName:");
    userNameLineEdit=new QLineEdit;
    serverIpLabel=new QLabel("server address:");
    serverIpLineEdit=new QLineEdit;
    portLabel=new QLabel("port:");
    portLineEdit=new QLineEdit;
    enterBtn=new QPushButton("enter chat room");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(content,0,0,1,2);
    mainLayout->addWidget(sendLineEdit,1,0);
    mainLayout->addWidget(sendBtn,1,1);
    mainLayout->addWidget(userNameLabel,2,0);
    mainLayout->addWidget(userNameLineEdit,2,1);
    mainLayout->addWidget(serverIpLabel,3,0);
    mainLayout->addWidget(serverIpLineEdit,3,1);
    mainLayout->addWidget(portLabel,4,0);
    mainLayout->addWidget(portLineEdit,4,1);
    mainLayout->addWidget(enterBtn,5,0,1,2);
    status=false;
    port=8010;
    portLineEdit->setText(QString::number(port));
    serverIp=new QHostAddress();
    connect(enterBtn,&QPushButton::clicked,this,&TcpClient::slotEnter);
    connect(sendBtn,&QPushButton::clicked,this,&TcpClient::slotSend);
    sendBtn->setEnabled(false);
}
void TcpClient::slotEnter()
{
    if(!status)
    {
        QString ip=serverIpLineEdit->text();
        if(!serverIp->setAddress(ip))
        {
            QMessageBox::information(this,"error","server ip address error!");
            return;
        }
        if(userNameLineEdit->text()=="")
        {
            QMessageBox::information(this,"error","user name error!");
            return;
        }
        userName=userNameLineEdit->text();
        tcpSocker=new QTcpSocket(this);
        connect(tcpSocker,&QTcpSocket::connected,this,&TcpClient::slotConnected);
        connect(tcpSocker,&QTcpSocket::disconnected,this,&TcpClient::slotDisconnected);
        connect(tcpSocker,&QTcpSocket::readyRead,this,&TcpClient::dataReceived);
        tcpSocker->connectToHost(*serverIp,port);
        status=true;
    }
    else {
        int length=0;
        QString msg=userName+":leave chat room";
        if((length=tcpSocker->write(msg.toLatin1(),msg.length()))!=msg.length())
        {
            return;
        }
        tcpSocker->disconnectFromHost();
        status=false;
    }
}
void TcpClient::slotConnected()
{
    sendBtn->setEnabled(true);
    enterBtn->setText("leave");
    int length=0;
    QString msg=userName+":enter chat room";
    if((length=tcpSocker->write(msg.toLatin1(),msg.length()))!=msg.length())
    {
        return;
    }
}
void TcpClient::slotDisconnected()
{
    sendBtn->setEnabled(false);
    enterBtn->setText("enter chat room");
}
void TcpClient::dataReceived()
{
    while (tcpSocker->bytesAvailable()>0) {
        QByteArray data;
        data.resize(tcpSocker->bytesAvailable());
        tcpSocker->read(data.data(),data.size());
        QString msg=data.data();
        content->addItem(msg.left(data.size()));
    }
}
void TcpClient::slotSend()
{
    if(sendLineEdit->text()=="")
    {
        return ;
    }
    QString msg=userName+":"+sendLineEdit->text();
    tcpSocker->write(msg.toLatin1(),msg.length());
    sendLineEdit->clear();
}
