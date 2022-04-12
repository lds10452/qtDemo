#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>

class shapeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit shapeWidget(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    QPoint dragPosition;
signals:

};

#endif // SHAPEWIDGET_H
