#include "transformwidget.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include "pixitem.h"
#include <math.h>
transFormWidget::transFormWidget(QWidget *parent) : QWidget(parent)
{
    angle=0;
    scaleValue=5;
    shearValue=5;
    translateValue=50;
    QGraphicsScene *scene=new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    QPixmap *pix=new QPixmap(":/res/images/image.png");
    pixItem *item=new pixItem(pix);
    scene->addItem(item);
    item->setPos(100,100);
    view=new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    ctrlFrame=new QFrame;
    creatFrame();
    QHBoxLayout *layout=new QHBoxLayout;
    layout->setMargin(10);
    layout->setSpacing(20);
    layout->addWidget(view);
    layout->addWidget(ctrlFrame);
    setLayout(layout);
    setWindowTitle(tr("view transform"));
}
void transFormWidget::creatFrame()
{
    QSlider *rotate=new QSlider;
    rotate->setOrientation(Qt::Horizontal);
    rotate->setRange(0,360);
    QHBoxLayout *rotateLay=new QHBoxLayout;
    rotateLay->addWidget(rotate);
    QGroupBox *rotateGroup=new QGroupBox(tr("rotate"));
    rotateGroup->setLayout(rotateLay);

    QSlider *scaleSlider = new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0,2*scaleValue);
    scaleSlider->setValue(scaleValue);
    QHBoxLayout *scaleLayout = new QHBoxLayout;
    scaleLayout->addWidget(scaleSlider);
    QGroupBox *scaleGroup = new QGroupBox(tr("Scale"));
    scaleGroup->setLayout(scaleLayout);
    //切变控制
    QSlider *shearSlider = new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0,2*shearValue);
    shearSlider->setValue(shearValue);
    QHBoxLayout *shearLayout = new QHBoxLayout;
    shearLayout->addWidget(shearSlider);
    QGroupBox *shearGroup = new QGroupBox(tr("Shear"));
    shearGroup->setLayout(shearLayout);
    //位移控制
    QSlider *translateSlider = new QSlider;
    translateSlider->setOrientation(Qt::Horizontal);
    translateSlider->setRange(0,2*translateValue);
    translateSlider->setValue(translateValue);
    QHBoxLayout *translateLayout = new QHBoxLayout;
    translateLayout->addWidget(translateSlider);
    QGroupBox *translateGroup = new QGroupBox(tr("Translate"));
    translateGroup->setLayout(translateLayout);
    connect(rotate,SIGNAL(valueChanged(int)),this,SLOT(slotRotate(int)));
    connect(scaleSlider,SIGNAL(valueChanged(int)),this,SLOT(slotScale(int)));
    connect(shearSlider,SIGNAL(valueChanged(int)),this,SLOT(slotShear(int)));
    connect(translateSlider,SIGNAL(valueChanged(int)),this,SLOT(slotTranslate(int)));
    //控制面板布局
    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->setMargin(10);
    frameLayout->setSpacing(20);
    frameLayout->addWidget(rotateGroup);
    frameLayout->addWidget(scaleGroup);
    frameLayout->addWidget(shearGroup);
    frameLayout->addWidget(translateGroup);
    ctrlFrame->setLayout(frameLayout);
}

void transFormWidget::slotScale(int value)
{
    qreal s;
    if(value>scaleValue)
        s=pow(1.1,value-scaleValue);
    else
        s=pow(1/1.1,scaleValue-value);
    view->scale(s,s);
    scaleValue=value;
}

void transFormWidget::slotShear(int value)
{
    view->shear((value-shearValue)/10.0,0);
    shearValue=value;
}
void transFormWidget::slotRotate(int value)
{
    view->rotate(value-angle);
}
void transFormWidget::slotTranslate(int value)
{
    view->translate(value-translateValue,value-translateValue);
    translateValue=value;
}
