#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>

class WorkThread : public QThread
{
public:
    WorkThread();
protected:
    void run() override;
};

#endif // WORKTHREAD_H
