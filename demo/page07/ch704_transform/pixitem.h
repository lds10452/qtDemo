#ifndef PIXITEM_H
#define PIXITEM_H
#include <QGraphicsItem>

class pixItem : public QGraphicsItem
{
public:
    pixItem(QPixmap *pixmap);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private:
    QPixmap pix;
};

#endif // PIXITEM_H
