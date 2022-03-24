#include "staritem.h"
#include <QPainter>
starItem::starItem()
{
    pix.load(":/res/images/star.png");
}
QRectF starItem::boundingRect() const
{
    return QRectF(-pix.width()/2,-pix.height()/2,pix.width(),pix.height());
}
void starItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),pix);
}
