#include "timeserver.h"
#include "timethread.h"
#include "timedialog.h"
TimeServer::TimeServer(QObject *parent):QTcpServer(parent)
{
    dlg=(TimeDialog*)parent;
}

void TimeServer::incomingConnection(qintptr handle)
{
    TimeThread *thread=new TimeThread(handle,0);
    connect(thread,SIGNAL(finished()),dlg,SLOT(slotShow()));	//(b)
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),
            Qt::DirectConnection);								//(c)
    thread->start();
}
