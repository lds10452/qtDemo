#include "shapewidget.h"
#include <QBitmap>
#include <QMouseEvent>
#include <QPainter>
shapeWidget::shapeWidget(QWidget *parent) : QWidget(parent)
{
    QPixmap pix;
    pix.load(":/res/images/image.png",0,Qt::AvoidDither|
             Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
}

void shapeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton)
        close();
}

void shapeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void shapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/res/images/image.png"));
}
