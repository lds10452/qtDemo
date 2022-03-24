#include "svgwindow.h"
#include "SvgWidget.h"
#include <QSvgRenderer>
#include <QMouseEvent>
#include <QScrollBar>
#include <QDebug>
SvgWindow::SvgWindow(QWidget *parent):QScrollArea(parent)
{
    svgWidget=new SvgWidget;
    setWidget(svgWidget);
}
void SvgWindow::setFile(QString fileName)
{
    svgWidget->load(fileName);
    QSvgRenderer *render=svgWidget->renderer();
    svgWidget->resize(render->defaultSize());
}
void SvgWindow::mousePressEvent(QMouseEvent *event)
{
//    mousePressPos=event->pos();
//    scrollValueOnPress.rx()=horizontalScrollBar()->value();
//    scrollValueOnPress.ry()=verticalScrollBar()->value();
//    qDebug()<<scrollValueOnPress.x()<<"## "<<mousePressPos.x();
//    event->accept();
}
void SvgWindow::mouseMoveEvent(QMouseEvent *e)
{
//    horizontalScrollBar()->setValue(scrollValueOnPress.x()-e->pos().x()+mousePressPos.x());
//    verticalScrollBar()->setValue(scrollValueOnPress.y()-e->pos().y()+mousePressPos.y());
//    horizontalScrollBar()->update();
//    verticalScrollBar()->update();
//    qDebug()<<e->pos().x()<<" !!"<<scrollValueOnPress.x()-e->pos().x()+mousePressPos.x();
//    e->accept();
}
