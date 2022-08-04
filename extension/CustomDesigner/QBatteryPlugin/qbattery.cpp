#include "qbattery.h"

QBattery::QBattery(QWidget *parent) :
    QWidget(parent)
{
}
void QBattery::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    //设置QPainter的绘图区
    QRect rect(0,0,width(),height());
    painter.setViewport(rect);
    painter.setWindow(0,0,120,50);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //设置画笔
    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    //设置画刷
    QBrush brush;
    brush.setColor(mColorBack);
    brush.setStyle(Qt::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    //改变rect的区域，绘制电池边框
    rect.setRect(1,1,109,48);
    painter.drawRect(rect);

    //改变画刷颜色，改变rect的区域，绘制电池的正极头
    brush.setColor(mColorBorder);
    painter.setBrush(brush);
    rect.setRect(110,15,10,20);
    painter.drawRect(rect);

    //画电池柱
    if(mPowerLevel>mWarnLevel) //正常颜色电量柱
    {
        brush.setColor(mColorPower);
        pen.setColor(mColorPower);
    }
    else//电量低时电量柱
    {
        brush.setColor(mColorWarning);
        pen.setColor(mColorWarning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    if(mPowerLevel>0)//如果当前有电量，绘制电量柱
    {
        rect.setRect(5,5,mPowerLevel,40);
        painter.drawRect(rect);
    }

    //绘制电量百分比文字
    QFontMetrics textSize(this->font());
    QString powerStr=QString::asprintf("%d%%",mPowerLevel);
    QRect textRect=textSize.boundingRect(powerStr); //得到字符串的rect
    painter.setFont(this->font());
    pen.setColor(mColorBorder);
    painter.setPen(pen);
    painter.drawText(55-textRect.width()/2,23+textRect.height()/2,powerStr);;

}

//设置当前电量
void QBattery::setPowerLevel(int pow)
{
    mPowerLevel=pow;
    emit powerLevelChanged(pow);
    repaint();
}

//得到当前电量
int QBattery::powerLevel()
{
    return mPowerLevel;
}

//设置电量低阀值
void QBattery::setWarnLevel(int warn)
{
    mWarnLevel=warn;
    repaint();
}

//得到电量低阀值
int QBattery::warnLevel()
{
    return mWarnLevel;
}

//返回组件尺寸大小
QSize QBattery::sizeHint()
{
    int H=this->height();
    int W=H*12/5;
    QSize size(W,H);
    return size;
}
