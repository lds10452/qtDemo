#ifndef SVGWIDGET_H
#define SVGWIDGET_H
#include <QSvgWidget>
//#include <QtSvg>
class SvgWidget : public QSvgWidget
{
    Q_OBJECT
public:
    SvgWidget(QWidget *parent=0);
protected:
    void wheelEvent(QWheelEvent*);
private:
    QSvgRenderer*render;
};

#endif // SVGWIDGET_H
