#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
class butterFly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit butterFly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *event) override;
    QRectF boundingRect()const;
signals:
protected:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;

};

#endif // BUTTERFLY_H
