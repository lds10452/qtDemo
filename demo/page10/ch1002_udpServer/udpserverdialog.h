#ifndef UDPSERVERDIALOG_H
#define UDPSERVERDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QUdpSocket>
class UdpServerDialog:public QDialog
{
    Q_OBJECT
public:
    UdpServerDialog(QWidget*p=0);
private:
    QLabel *timerLabel;
    QLineEdit *textLineEdit;
    QPushButton *btn;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
private slots:
    void btnClicked();
    void timeOut();

};

#endif // UDPSERVERDIALOG_H
