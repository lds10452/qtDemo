#ifndef TRANSFORMWIDGET_H
#define TRANSFORMWIDGET_H

#include <QWidget>
#include <QGraphicsView>
class transFormWidget : public QWidget
{
    Q_OBJECT
public:
    explicit transFormWidget(QWidget *parent = nullptr);
    void creatFrame();
private:
    int angle;
    int scaleValue;
    int shearValue;
    int translateValue;
    QGraphicsView *view;
    QFrame *ctrlFrame;
public slots:
    void slotRotate(int);
    void slotScale(int);
    void slotShear(int);
    void slotTranslate(int);
signals:

};

#endif // TRANSFORMWIDGET_H
