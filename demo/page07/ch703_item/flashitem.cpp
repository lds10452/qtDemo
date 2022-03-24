#include "flashitem.h"
#include <QPainter>
flashItem::flashItem(QObject *parent) : QObject(parent)
{
    flash=true;
    setFlag(ItemIsMovable);
    startTimer(1000);
}
QRectF flashItem::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-10-adjust,-10-adjust,43+adjust,43+adjust);
}
void flashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7,-7,40,40);
    painter->setPen(QPen(Qt::black,0));
    painter->setBrush(flash?(Qt::red):(Qt::yellow));
    painter->drawEllipse(-10,-10,40,40);
}
void flashItem::timerEvent(QTimerEvent *event)
{
    flash=!flash;
    update();
}
