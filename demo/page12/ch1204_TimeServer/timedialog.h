#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H
#include <QDialog>
class QLabel;
class TimeServer;
class TimeDialog : public QDialog
{
    Q_OBJECT
public:
    TimeDialog(QWidget *p=0);
    QLabel *countLabel;
    TimeServer *timerServer;
    int count;
public slots:
    void slotShow();
};

#endif // TIMEDIALOG_H
