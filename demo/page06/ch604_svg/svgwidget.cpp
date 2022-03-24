#include "svgwidget.h"
#include <QSvgRenderer>
#include <QWheelEvent>
SvgWidget::SvgWidget(QWidget *parent):QSvgWidget(parent)
{
    render=renderer();
}
void SvgWidget::wheelEvent(QWheelEvent*e)
{
    const double diff=0.1;
    //QSize size=render->defaultSize();
    int width=this->width();
    int height=this->height();
    if(e->delta()>0)
    {
        width=this->width()+this->width()*diff;
        height=this->height()+this->height()*diff;
    }
    else {
        width=this->width()-this->width()*diff;
        height=this->height()-this->height()*diff;
    }
    resize(width,height);
}
