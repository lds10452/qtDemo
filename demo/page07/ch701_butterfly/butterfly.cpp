#include "butterfly.h"
#include <math.h>
#define PI 3.14159
butterFly::butterFly(QObject *parent) : QObject(parent)
{
    up=true;
    pix_up.load(":/res/images/butter_up.png");
    pix_down.load(":/res/images/butter_down.png");
    startTimer(100);
    qsrand((unsigned)time(NULL));
}
QRectF butterFly::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-pix_up.width()/2-adjust,
                  -pix_up.height()/2-adjust,
                  pix_up.width()+adjust*2,
                  pix_up.height()+adjust*2);
}
void butterFly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(up)
    {
        painter->drawPixmap(boundingRect().topLeft(),pix_up);
        up=!up;
    }
    else {
        painter->drawPixmap(boundingRect().topLeft(),pix_down);
        up=!up;
    }
}
void butterFly::timerEvent(QTimerEvent *event)
{
    qreal edgex=scene()->sceneRect().right()+boundingRect().width()/2;
    qreal edgetop=scene()->sceneRect().top()+boundingRect().height()/2;
    qreal edgeBottom=scene()->sceneRect().bottom()+boundingRect().height()/2;
    if(pos().x()>=edgex)
        setPos(scene()->sceneRect().left(),pos().y());
    if(pos().y()<=edgetop)
        setPos(pos().x(),scene()->sceneRect().bottom());
    if(pos().y()>=edgeBottom)
        setPos(pos().x(),scene()->sceneRect().top());
    angle+=(qrand()%10/20.0);
    qreal dx=fabs(sin(angle*PI)*10.0);
    qreal dy=(qrand()%20)-10.0;
    setPos(mapToParent(dx,dy));
}
