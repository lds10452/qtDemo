#ifndef TIMETHREAD_H
#define TIMETHREAD_H
#include <QThread>
#include <QTcpSocket>
class TimeThread : public QThread
{
    Q_OBJECT
public:
    TimeThread(int dsp,QObject *parent=0);
    void run() override;
    int socketDsp;
signals:
    void error(QTcpSocket::SocketError error);
};

#endif // TIMETHREAD_H
