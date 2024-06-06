#include "colorselectwidget.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ColorSelectWidget w(SCREEN_COLOR_THREE,SCREEN_GRAY_MIDDLE,QColor(240,0,0));
    w.exec();
    QColor color=w.m_CurSelectColor;
//    QObject::connect(&w,&ColorSelectWidget::ColorSelectFinish,[](QColor color){
        if(!color.isValid())
        {
            qDebug()<<"color is invalid";
        }
        else {
            qDebug("%d,%d,%d",color.red(),color.green(),color.blue());
        }
//    });
//    w.show();
    return a.exec();
}
