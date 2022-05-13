#include "udpclientdialog.h"
#include <QMessageBox>
#include <QHostAddress>
UdpClientDialog::UdpClientDialog(QWidget*p):QDialog(p)
{
    recTextEdit=new QTextEdit;
    closeBtn=new QPushButton("close");
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(recTextEdit);
    mainLayout->addWidget(closeBtn);
    connect(closeBtn,&QPushButton::clicked,this,&UdpClientDialog::btnClicked);
    port=5555;
    udpSocket=new QUdpSocket(this);
    connect(udpSocket,&QUdpSocket::readyRead,this,&UdpClientDialog::dataRec);
    bool res=udpSocket->bind(port);
    if(!res)
    {
        QMessageBox::information(this,"error","udp socket creat error!");
        return;
    }
}

void UdpClientDialog::btnClicked()
{
    close();
}

void UdpClientDialog::dataRec()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        recTextEdit->insertPlainText(msg);
    }
}
