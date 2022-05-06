#ifndef WAITCONDITIONDIALOG_H
#define WAITCONDITIONDIALOG_H
#include <QDialog>
#include <QThread>
class WaitConditionDialog : public QDialog
{
    Q_OBJECT
public:
    WaitConditionDialog();
private slots:
    void slotStart();
};

class ProducerA:public QThread
{
protected:
    void run() override;
};

class ConsumerA:public QThread
{
protected:
    void run() override;
};

#endif // WAITCONDITIONDIALOG_H
