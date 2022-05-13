#ifndef UDPCLIENTDIALOG_H
#define UDPCLIENTDIALOG_H
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
class UdpClientDialog:public QDialog
{
    Q_OBJECT
public:
    UdpClientDialog(QWidget*p=0);
private:
    QTextEdit *recTextEdit;
    QPushButton *closeBtn;
    QVBoxLayout *mainLayout;
    int port;
    QUdpSocket *udpSocket;
private slots:
    void btnClicked();
    void dataRec();
};

#endif // UDPCLIENTDIALOG_H
