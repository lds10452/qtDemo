#include "paintwidget.h"
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QDebug>
PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::red));
    setAutoFillBackground(true);
    pix=new QPixmap(size());
    pix->fill(Qt::white);
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    rect.setTopLeft(event->pos());
    path-=path;
    path.addRect(rect);
    update();
    QWidget::mouseMoveEvent(event);
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    rect.setBottomRight(event->pos());
    QWidget::mousePressEvent(event);
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    path-=path;
    update();
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    pix->fill(Qt::white);
    qDebug()<<rect.left()<<" "<<rect.top()<<" "<<rect.right()<<" "<<rect.bottom();
    QPainter p1(pix);
    QPen pen;
    pen.setWidth(2);
    pen.setStyle(Qt::DotLine);
    pen.setColor(Qt::red);
    p1.setPen(pen);
    p1.setBrush(Qt::blue);
    p1.drawPath(path);
    QPainter p2(this);
    p2.drawPixmap(0,0,*pix);
}
