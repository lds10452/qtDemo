#ifndef STARITEM_H
#define STARITEM_H

#include <QGraphicsItem>
class starItem : public QGraphicsItem
{
public:
    starItem();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
    QPixmap pix;
signals:

};

#endif // STARITEM_H
