#include "keyeventdialog.h"
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
KeyEventDialog::KeyEventDialog()
{
    width=512;
    height=256;
    resize(width,height);
    setMinimumSize(width,height);
    setMaximumSize(width,height);
    pix=new QPixmap(width,height);
    pix->fill(Qt::white);
    img.load(":/res/images/rab.png");
    startX=80;
    startY=80;
    step=20;
    drawPix();
}

void KeyEventDialog::drawPix()
{
    pix->fill(Qt::white);
    QPainter painter(pix);
    painter.setPen(QPen(Qt::DotLine));
    for (int i=step;i<width;i+=step) {
        painter.drawLine(i,0,i,height);
    }
    for (int j=step;j<height;j+=step) {
        painter.drawLine(0,j,width,j);
    }
    painter.drawPixmap(startX,startY,img);
}

void KeyEventDialog::keyPressEvent(QKeyEvent *event)
{
    int offset;
    if(event->modifiers()==Qt::ControlModifier)
    {
        offset=1;
    }
    else {
        startX=startX-startX%step;
        startY=startY-startY%step;
        offset=step;
    }
    if(event->key()==Qt::Key_Left)
    {
        startX=(startX-offset<0)?startX:startX-offset;
    }
    if(event->key()==Qt::Key_Right)
    {
        startX=(startX+offset+img.width()>width)?startX:startX+offset;
    }
    if(event->key()==Qt::Key_Up)
    {
        startY=(startY-offset<0)?startY:startY-offset;
    }
    if(event->key()==Qt::Key_Down)
    {
        startY=(startY+offset+img.height()>height)?startY:startY+offset;
    }
    if(event->key()==Qt::Key_Home)
    {
        startX=0;
        startY=0;
    }
    if(event->key()==Qt::Key_End)
    {
        startX=width-img.width();
        startY=height-img.height();
    }
    drawPix();
    update();
}

void KeyEventDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,*pix);
}
