#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void clear();
public:
    QPixmap *pix;
    int style;
    int weight;
    QColor color;
    QPoint startPos;
    QPoint endPos;
signals:

};

#endif // DRAWWIDGET_H
