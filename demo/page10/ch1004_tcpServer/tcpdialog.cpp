#include "tcpdialog.h"
#include "tcpserver.h"
TcpDialog::TcpDialog(QWidget *p):QDialog(p)
{
    setWindowTitle("server");
    content=new QListWidget;
    portLabel=new QLabel("port");
    portLineEdit=new QLineEdit;
    createBtn=new QPushButton("create chat room");
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(content,0,0,1,2);
    mainLayout->addWidget(portLabel,1,0);
    mainLayout->addWidget(portLineEdit,1,1);
    mainLayout->addWidget(createBtn,2,0,1,2);
    port=8010;
    portLineEdit->setText(QString::number(port));
    connect(createBtn,&QPushButton::clicked,this,&TcpDialog::slotCreatServer);

}

void TcpDialog::slotCreatServer()
{
    server =new TcpServer(this,port);
    connect(server,&TcpServer::updateServer,this,&TcpDialog::updateServer);
    createBtn->setEnabled(false);
}

void TcpDialog::updateServer(QString msg, int length)
{
    content->addItem(msg.left(length));
}
