#ifndef EVENTFILTERDIALOG_H
#define EVENTFILTERDIALOG_H
#include <QDialog>
class QPixmap;
class QLabel;
class eventFilterDialog : public QDialog
{
public:
    eventFilterDialog();
public slots:
    bool eventFilter(QObject *, QEvent *);
private:
    QPixmap *pix1;
    QPixmap *pix2;
    QPixmap *pix3;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *showLabel;
};

#endif // EVENTFILTERDIALOG_H
