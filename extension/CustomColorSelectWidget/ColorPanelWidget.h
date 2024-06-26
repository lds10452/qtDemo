﻿#ifndef COLORAREAWIDGET_H
#define COLORAREAWIDGET_H

#include <QWidget>
#include <vector>
using namespace std;
enum SCREEN_COLOR:int
{
    SCREEN_COLOR_SINGLE = 1, //单基色
    SCREEN_COLOR_DOUBLE = 2, //双基色
    SCREEN_COLOR_THREE = 3, //三基色
    SCREEN_COLOR_FULLCOLOR = 4, //全彩色
};
enum SCREEN_GRAY
{
    SCREEN_GRAY_NO=0,
    SCREEN_GRAY_LOW,
    SCREEN_GRAY_MIDDLE,
    SCREEN_GRAY_HIGH,
    SCREEN_GRAY_HIGH6
};

class ColorPanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPanelWidget(QWidget *parent = nullptr);
    ~ColorPanelWidget();

signals:
    void ColorChange(QColor,bool btnSelect);
protected:

    virtual void paintEvent(QPaintEvent *event)override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

public:
    QPoint m_curPoint;//点击的坐标
    void InitColorPanel(SCREEN_COLOR color,SCREEN_GRAY gray,int bits,int maxColorValue);
    static int AddOneToLastBits(int color,int bits);
private:
    SCREEN_GRAY m_enumScreenGray;
    SCREEN_COLOR m_enumScreenColor;
    int m_nHighBitsNum;//高几位
    vector<QColor> m_vecColorBase;//横向颜色过渡色
    int m_nMaxColorVaule;//最大颜色值
    int m_nColorSpace;//相邻颜色差值
    int m_nColorSplice;//过渡次数
    void DrawColorPanel(QPainter*painter);
    void CalcColor(QPoint point);
    void drawCursor(QPainter *painter);

    QImage *image;
    void DrawColorImage();

    int ModColor(int color);
public slots:
    void CalcCrossPos(QColor color);
};

#endif // COLORAREAWIDGET_H
