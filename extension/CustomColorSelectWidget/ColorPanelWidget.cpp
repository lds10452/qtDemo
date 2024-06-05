#include "ColorPanelWidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

#define COLOR_MUTI 3
#define MAX_COLOR_VALUE 255
ColorPanelWidget::ColorPanelWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(255,255);
    m_vecColorBase.clear();
}

void ColorPanelWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    DrawColorPanel(&painter);
    drawCursor(&painter);
}

void ColorPanelWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->type()!=QEvent::MouseMove)
    {
        CalcColor(event->pos());
    }
}

void ColorPanelWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x=qBound(0,event->pos().x(),width());
    int y=qBound(0,event->pos().y(),height());
//    qDebug("%d,%d",x,y);
    CalcColor(QPoint(x,y));
}



void ColorPanelWidget::InitColorPanel(SCREEN_COLOR color,SCREEN_GRAY gray,int bits,int maxColorValue)
{
    m_enumScreenColor=color;
    switch (m_enumScreenColor) {
    case SCREEN_COLOR_SINGLE:
        m_nColorSplice=1;
        break;
    case SCREEN_COLOR_DOUBLE:
        m_nColorSplice=1;
        break;
    case SCREEN_COLOR_THREE:
        m_nColorSplice=3;
        break;
    default:
        m_nColorSplice=1;
        break;
    }

    m_enumScreenGray=gray;
    m_nHighBitsNum=bits;
//    switch (m_enumScreenGray) {
//    case LOWER_GRAY:
//        m_nHighBitsNum=2;
//        break;
//    case MED_GRAY:
//        m_nHighBitsNum=4;
//        break;
//    case HIGH_GRAY:
//        m_nHighBitsNum=6;
//        break;
//    default:
//        m_nHighBitsNum=1;
//        break;
//    }
    m_nColorSpace=256/pow(2,m_nHighBitsNum);

    m_nMaxColorVaule=maxColorValue;

    m_vecColorBase.clear();
    switch (m_enumScreenColor) {
    case SCREEN_COLOR_SINGLE:
        m_vecColorBase.push_back(QColor(0,0,0));
        m_vecColorBase.push_back(QColor(0,0,0));
        break;
    case SCREEN_COLOR_DOUBLE:
        m_vecColorBase.push_back(QColor(0,0,0));
        m_vecColorBase.push_back(QColor(0,m_nMaxColorVaule,0));
        break;
    case SCREEN_COLOR_THREE:
        m_vecColorBase.push_back(QColor(0,0,0));
        m_vecColorBase.push_back(QColor(0,0,m_nMaxColorVaule/2));

        m_vecColorBase.push_back(QColor(0,0,m_nMaxColorVaule));
        m_vecColorBase.push_back(QColor(0,m_nMaxColorVaule/2,m_nMaxColorVaule));

        m_vecColorBase.push_back(QColor(0,m_nMaxColorVaule,m_nMaxColorVaule));
        m_vecColorBase.push_back(QColor(0,m_nMaxColorVaule,m_nMaxColorVaule/2));

        m_vecColorBase.push_back(QColor(0,m_nMaxColorVaule,0));
        break;
    default:
        m_vecColorBase.clear();
        break;
    }
}

void ColorPanelWidget::DrawColorPanel(QPainter *painter)
{
    painter->save();
    int w = width();
    int h = height();
    // 设置混合模式为正常
//    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    int num=m_vecColorBase.size()-1;
    for (int i=0;i<num;i++) {
        float offset=(float)i/num;
        float offset2=(float)(i+1)/num;
        QLinearGradient gradient1(w*offset, 0, w*offset2, 0);
        gradient1.setColorAt(offset, m_vecColorBase[i]);
        gradient1.setColorAt(offset2, m_vecColorBase[i+1]);

//        painter.setBrush(gradient1);
//        painter.drawRect(0, 0, w / 2, h);
        painter->fillRect(w*offset, 0, w*offset2 , h,gradient1);
    }
    // 设置混合模式为叠加
    painter->setCompositionMode(QPainter::CompositionMode_Plus);

    // 定义两种颜色
    QColor color1(0, 0, 0);
    QColor color2(m_nMaxColorVaule, 0, 0); // 红色
    // 创建第二个渐变
    QLinearGradient gradient2(0, 0, 0, h);
    gradient2.setColorAt(0, color1);
    gradient2.setColorAt(1, color2);
    painter->fillRect(0, 0, w , h,gradient2);
    painter->restore();
}

void ColorPanelWidget::CalcColor(QPoint point)
{
    m_curPoint=point;
    int posX=point.x();
    int posY=point.y();
    int r=0,g=0,b=0;
    switch (m_nColorSplice) {
    case 1:
    {
        if(m_enumScreenColor==SCREEN_COLOR_DOUBLE)//横向一段：g:0->max,纵向一段：r:0->max
        {
            g=posX*m_nMaxColorVaule/MAX_COLOR_VALUE;
        }
        break;
    }
    case 3://横向三段：b：0->max,max,max->; g:0,0->max,max
    {
        int range=MAX_COLOR_VALUE/m_nColorSplice;
        if(posX<=range)
        {
            b=posX*m_nColorSplice*m_nMaxColorVaule/MAX_COLOR_VALUE;
        }
        else if (posX>range&&(posX<=(2*range))) {
            b=m_nMaxColorVaule;
            g=(posX-range)*m_nColorSplice*m_nMaxColorVaule/MAX_COLOR_VALUE;
        }
        else {
            b=(MAX_COLOR_VALUE*m_nColorSplice-m_nColorSplice*posX)*m_nMaxColorVaule/MAX_COLOR_VALUE;
            g=m_nMaxColorVaule;
        }
        break;
    }
    default:
        break;
    }
    r=posY*m_nMaxColorVaule/MAX_COLOR_VALUE;
    r=r/m_nColorSpace*m_nColorSpace;
    g=g/m_nColorSpace*m_nColorSpace;
    b=b/m_nColorSpace*m_nColorSpace;
    emit ColorChange(QColor(r,g,b),false);

    update();
}

void ColorPanelWidget::CalcCrossPos(QColor color)
{
    int r=color.red();
    int g=color.green();
    int b=color.blue();
    int yPos=r*MAX_COLOR_VALUE/m_nMaxColorVaule;
    int xPos=0;
    switch (m_nColorSplice) {
    case 1:
    {
        if(m_enumScreenColor==SCREEN_COLOR_DOUBLE)
        {
            xPos=g*MAX_COLOR_VALUE/m_nMaxColorVaule;
        }
        break;
    }
    case 3:
    {
        int range=MAX_COLOR_VALUE/m_nColorSplice;
        if(0>=g)
        {
            xPos=b*range/m_nMaxColorVaule;
        }
        else if (g>=m_nMaxColorVaule) {
            xPos=2*range+range-range*b/m_nMaxColorVaule;
        }
        else {
            xPos=g*range/m_nMaxColorVaule+range;
        }
        break;
    }
    default:
        break;
    }
    m_curPoint.setX(xPos);
    m_curPoint.setY(yPos);
    update();
}

void ColorPanelWidget::drawCursor(QPainter *painter)
{
//    painter->setCompositionMode(QPainter::CompositionMode_Clear);
    painter->save();
    painter->setPen(Qt::white);

    QString text = "+";

    QFont textFont;
    int size = 40 ;
    textFont.setPixelSize(size);

    //计算文字的宽度高度,自动移到鼠标按下处的中心点
    QFontMetrics fm(textFont);
    int textWidth = fm.width(text);
    int textHeight = fm.height();
    QPoint textPoint = m_curPoint - QPoint(textWidth / 2, -(textHeight*3 / 8));

    QPainterPath path;
    path.addText(textPoint, textFont, text);
    painter->drawPath(path);
    painter->restore();
}
