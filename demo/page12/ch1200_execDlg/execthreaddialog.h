#ifndef EXECTHREADDIALOG_H
#define EXECTHREADDIALOG_H
#include <QDialog>

class ExecThreadDialog : public QDialog
{
    Q_OBJECT
public:
    ExecThreadDialog();
private slots:
    void BaseThread();
    void SemaphoreThread();
    void WaitCondition();
};

#endif // EXECTHREADDIALOG_H
