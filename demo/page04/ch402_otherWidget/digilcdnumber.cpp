#include "digilcdnumber.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
DigiLCDNumber::DigiLCDNumber(QWidget *p):QLCDNumber(p)
{
    QPalette pp=palette();
    pp.setColor(QPalette::Window,Qt::blue);
    setPalette(pp);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    showTime();
    resize(150,60);
    showColon=true;
}

void DigiLCDNumber::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        dragPos=e->globalPos()-frameGeometry().topLeft();
        e->accept();
    }
    if(e->button()==Qt::RightButton)
    {
        close();
    }
}

void DigiLCDNumber::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton)
    {
        move(e->globalPos()-dragPos);
        e->accept();
    }
}

void DigiLCDNumber::showTime()
{
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm");
    if(showColon)
    {
        text[2]=':';
        showColon=false;
    }
    else {
        text[2]=' ';
        showColon=true;
    }
    display(text);
}
