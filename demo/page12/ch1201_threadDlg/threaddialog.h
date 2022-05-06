#ifndef THREADDIALOG_H
#define THREADDIALOG_H
#include <QDialog>
#define MAXSIZE 5
class WorkThread;
class QPushButton;
class ThreadDialog : public QDialog
{
    Q_OBJECT
public:
    ThreadDialog();
    WorkThread *workThread[MAXSIZE];
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
private slots:
    void slotStart();
    void slotStop();
};

#endif // THREADDIALOG_H
