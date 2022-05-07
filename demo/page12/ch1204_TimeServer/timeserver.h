#ifndef TIMESERVER_H
#define TIMESERVER_H
#include <QTcpServer>
class TimeDialog;
class TimeServer : public QTcpServer
{
    Q_OBJECT
public:
    TimeServer(QObject *parent=0);
protected:
    void incomingConnection(qintptr handle) override;
private:
    TimeDialog *dlg;
};

#endif // TIMESERVER_H
