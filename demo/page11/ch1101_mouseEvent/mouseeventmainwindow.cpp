#include "mouseeventmainwindow.h"
#include <QLabel>
#include <QStatusBar>
#include <QMouseEvent>
#include "paintwidget.h"
mouseEventMainWindow::mouseEventMainWindow(QWidget *parent) : QMainWindow(parent)
{
    PaintWidget *w=new PaintWidget;
    setCentralWidget(w);
    QLabel *label=new QLabel;
    label->setText("移动位置:");
    label->setFixedWidth(100);
    mousePos=new QLabel;
    mousePos->setText(" ");
    mousePos->setFixedWidth(100);
    statusBar()->addPermanentWidget(label);
    statusBar()->addPermanentWidget(mousePos);
    setMouseTracking(true);
    resize(400,200);
}

void mouseEventMainWindow::mousePressEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+
            QString::number(e->y())+")";
    if(e->button()==Qt::LeftButton)
    {
        str="左键:"+str;
    }
    else if(e->button()==Qt::RightButton)
    {
        str="右键:"+str;
    }
    else if (e->button()==Qt::MidButton) {
        str="中键:"+str;
    }
    statusBar()->showMessage(str);
}

void mouseEventMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mousePos->setText("("+QString::number(e->x())+","+
                      QString::number(e->y())+")");
}

void mouseEventMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+
            QString::number(e->y())+")";
    statusBar()->showMessage("释放在:"+str,3000);
}

void mouseEventMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    QString str="("+QString::number(e->x())+","+
            QString::number(e->y())+")";
    statusBar()->showMessage("双击在:"+str);
}
