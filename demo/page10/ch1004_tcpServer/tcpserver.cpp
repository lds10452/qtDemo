#include "tcpserver.h"
#include "tcpclientsocket.h"
TcpServer::TcpServer(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}
void TcpServer::incomingConnection(qintptr handle)
{
    TcpClientSocket *socket=new TcpClientSocket();
    connect(socket,&TcpClientSocket::updateClients,this,&TcpServer::updateClients);
    connect(socket,&TcpClientSocket::disconnected,this,&TcpServer::slotDisconnected);
    socket->setSocketDescriptor(handle);
    clientList.append(socket);
}
void TcpServer::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);
    for(int i=0;i<clientList.count();i++)
    {
        QTcpSocket *item=clientList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }
}
void TcpServer::slotDisconnected(int desc)
{
    for(int i=0;i<clientList.count();i++)
    {
        QTcpSocket *item=clientList.at(i);
        if(item->socketDescriptor()==desc)
        {
            clientList.removeAt(i);
            return;
        }
    }
}
