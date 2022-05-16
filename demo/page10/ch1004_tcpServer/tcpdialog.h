#ifndef TCPDIALOG_H
#define TCPDIALOG_H
#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
class TcpServer;
class TcpDialog:public QDialog
{
    Q_OBJECT
public:
    TcpDialog(QWidget *p=0);
private:
    QListWidget *content;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *createBtn;
    QGridLayout *mainLayout;
    int port;
    TcpServer *server;
public slots:
    void slotCreatServer();
    void updateServer(QString,int);
};

#endif // TCPDIALOG_H
