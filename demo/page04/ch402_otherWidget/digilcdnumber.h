#ifndef DIGILCDNUMBER_H
#define DIGILCDNUMBER_H
#include <QLCDNumber>
#include <QMouseEvent>
class DigiLCDNumber : public QLCDNumber
{
    Q_OBJECT
public:
    DigiLCDNumber(QWidget *p=NULL);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private slots:
    void showTime();
private:
    QPoint dragPos;
    bool showColon;
};

#endif // DIGILCDNUMBER_H
