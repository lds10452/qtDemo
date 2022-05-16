#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QHostAddress>
#include <QTcpSocket>
class TcpClient:public QDialog
{
    Q_OBJECT
public:
    TcpClient(QWidget*p=0);
private:
    QListWidget *content;
    QLineEdit *sendLineEdit;
    QPushButton *sendBtn;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *serverIpLabel;
    QLineEdit *serverIpLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *enterBtn;
    QGridLayout *mainLayout;
    bool status;
    int port;
    QHostAddress *serverIp;
    QString userName;
    QTcpSocket *tcpSocker;
public slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
    void slotSend();
};

#endif // TCPCLIENT_H
