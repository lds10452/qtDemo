#ifndef SVGWINDOW_H
#define SVGWINDOW_H
#include <QScrollArea>
class SvgWidget;
class SvgWindow : public QScrollArea
{
    Q_OBJECT
public:
    SvgWindow(QWidget *parent=0);
    void setFile(QString);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
private:
    SvgWidget*svgWidget;
    QPoint mousePressPos;
    QPoint scrollValueOnPress;
};

#endif // SVGWINDOW_H
