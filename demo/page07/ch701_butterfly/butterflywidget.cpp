#include "butterflywidget.h"
#include "butterfly.h"
#include <QHBoxLayout>
ButterflyWidget::ButterflyWidget(QWidget *parent) : QWidget(parent)
{
    QGraphicsScene *scene=new QGraphicsScene;
    scene->setSceneRect(QRectF(-200,-200,400,400));
    butterFly *butter=new butterFly;
    butter->setPos(-100,0);
    scene->addItem(butter);
    QGraphicsView *view=new QGraphicsView;
    view->setScene(scene);
    QHBoxLayout *lyout=new QHBoxLayout(this);
    lyout->addWidget(view);
}
