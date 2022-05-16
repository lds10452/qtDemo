#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
class TcpClientSocket;
class TcpServer:public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent=0,int port=0);
    QList<TcpClientSocket*>clientList;
signals:
    void updateServer(QString ,int);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(qintptr handle) override;
};

#endif // TCPSERVER_H
