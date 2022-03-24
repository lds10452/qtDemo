#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QObject>
#include <QGraphicsItem>
class flashItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit flashItem(QObject *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void timerEvent(QTimerEvent *event) override;

private:
    bool flash;
signals:

};

#endif // FLASHITEM_H
