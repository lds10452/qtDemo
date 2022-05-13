#ifndef NETWORKDIALOG_H
#define NETWORKDIALOG_H
#include <QDialog>

class NetWorkDialog:public QDialog
{
    Q_OBJECT
public:
    NetWorkDialog();
private slots:
    void ShowNetworkInfo();
    void ShowUdpServer();
    void SHowUdpClient();
};

#endif // NETWORKDIALOG_H
