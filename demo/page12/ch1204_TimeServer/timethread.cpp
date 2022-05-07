#include "timethread.h"
#include <QDateTime>
#include <QByteArray>
#include <QDataStream>
TimeThread::TimeThread(int dsp,QObject *parent):QThread(parent),socketDsp(dsp)
{

}

void TimeThread::run()
{
    QTcpSocket tcpSocket;
    if(!tcpSocket.setSocketDescriptor(socketDsp))
    {
        emit error(tcpSocket.error());
        return;
    }
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_8);
    uint time2u=QDateTime::currentDateTime().toTime_t();
    out<<time2u;
    tcpSocket.write(block);
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
