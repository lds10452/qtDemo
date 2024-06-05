#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>
#include "ColorPanelWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ColorSelectWidget; }
QT_END_NAMESPACE
enum SCREEN_COLOR:int;
enum SCREEN_GRAY;
class QPushButton;
typedef struct COLOR_NUM
{
    int RedNum;
    int GreenNum;
    int BlueNum;
}ColorNum;
class ColorSelectWidget : public QDialog
{
    Q_OBJECT

public:
    ColorSelectWidget(SCREEN_COLOR color,SCREEN_GRAY gray,QColor defaultColor,QWidget *parent = nullptr);
    ~ColorSelectWidget();
signals:
    void ColorSelectFinish(QColor color);
    void ColorToPos(QColor);
private slots:
    void UpdateColor(QColor color,bool btnSelect);
    void ColorClicked();
    void on_ptnAddColor_clicked();

    void PushButtonClickFinish();

private:
    Ui::ColorSelectWidget *ui;
    void InitWidget();
public:
    QColor m_CurSelectColor;
    void translateUi();
private:
    SCREEN_COLOR m_ScreenColor;
    SCREEN_GRAY m_ScreenGray;
    int m_nHighBitsNum;//高几位
    int m_nMaxColorVaule;//最大颜色值
//    int m_nColorSpace;
    int m_nRedNum;//该颜色分量数量
    int m_nGreenNum;
    int m_nBlueNum;
    int m_nCustomColorCount;//自定义颜色数量
    static ColorNum colorNum[3][3];//各色屏组合各灰度对应各颜色分量数量
    QPushButton* m_arrCustomBtn[16];//自定义按钮
    QPushButton* m_pLastSelectButton;
    QColor m_TempSelectColor;
    void DrawBaseColor();
    void DrawCustomColor();
};
#endif // WIDGET_H
