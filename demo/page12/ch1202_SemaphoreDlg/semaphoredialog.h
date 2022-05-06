#ifndef SEMAPHOREDIALOG_H
#define SEMAPHOREDIALOG_H
#include <QDialog>
#include <QThread>
class SemaphoreDialog : public QDialog
{
    Q_OBJECT
public:
    SemaphoreDialog();

private slots:
    void slotStart();
};

class Consumer:public QThread
{
protected:
    void run() override;
};

class Producter:public QThread
{
protected:
    void run() override;
};

#endif // SEMAPHOREDIALOG_H
