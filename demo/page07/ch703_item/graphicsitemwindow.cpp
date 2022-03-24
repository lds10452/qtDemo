#include "graphicsitemwindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "flashitem.h"
#include "staritem.h"
GraphicsItemWindow::GraphicsItemWindow(QWidget *parent) : QMainWindow(parent)
{
    createMenu();
    scene=new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    initScene();
    QGraphicsView *view=new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("graphics item"));
}
void GraphicsItemWindow::createMenu()
{
    QAction *newAct=new QAction(tr("new"));
    QAction *clearAct=new QAction(tr("clear"),this);
    QAction *exitAct=new QAction(tr("exit"),this);
    QAction *ellipse=new QAction(tr("add ellipse"),this);
    QAction *polygon=new QAction(tr("add polygon"),this);
    QAction *text=new QAction(tr("add text"),this);
    QAction *rect=new QAction(tr("add rect"),this);
    QAction *pic=new QAction(tr("add pic"),this);
    connect(newAct,SIGNAL(triggered()),this,SLOT(slotNew()));
    connect(clearAct,SIGNAL(triggered()),this,SLOT(slotClear()));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));
    connect(ellipse,SIGNAL(triggered()),this,SLOT (slotAddEllipseItem()));
    connect(polygon,SIGNAL(triggered()),this,SLOT (slotAddPolygonItem()));
    connect(text,SIGNAL(triggered()),this,SLOT (slotAddTextItem()));
    connect(rect,SIGNAL(triggered()),this,SLOT (slotAddRectItem()));
    connect(pic,SIGNAL(triggered()),this,SLOT (slotAddAlphaItem()));
    QAction *flash = new QAction(tr("加入闪烁圆"),this);
    connect(flash,SIGNAL(triggered()),this,SLOT(slotAddFlashItem()));
    QAction *animte = new QAction(tr("加入 星星"),this);
    connect(animte,SIGNAL(triggered()),this,SLOT(slotAddStarItem()));
    QMenu *menu=menuBar()->addMenu(tr("file"));
    menu->addAction(newAct);
    menu->addAction(clearAct);
    menu->addSeparator();
    menu->addAction(exitAct);
    QMenu *itemMenu=menuBar()->addMenu(tr("item"));
    itemMenu->addAction(ellipse);
    itemMenu->addAction(polygon);
    itemMenu->addAction(text);
    itemMenu->addAction(rect);
    itemMenu->addAction(pic);
    itemMenu->addAction(flash);
    itemMenu->addAction(animte);
}
void GraphicsItemWindow::initScene()
{
    int i;
    for (i=0;i<3;i++) {
        slotAddEllipseItem();
        slotAddPolygonItem();
        slotAddTextItem();
        slotAddRectItem();
        slotAddAlphaItem();
        slotAddFlashItem();
        slotAddStarItem();
    }
}
void GraphicsItemWindow::slotNew()
{
    slotClear();
    initScene();
    GraphicsItemWindow *newWin=new GraphicsItemWindow;
    newWin->show();
}
void GraphicsItemWindow::slotClear()
{
    QList<QGraphicsItem*>listItem=scene->items();
    while (!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}
void GraphicsItemWindow::slotAddEllipseItem()
{
    QGraphicsEllipseItem *item=new QGraphicsEllipseItem(QRectF(0,0,80,60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void GraphicsItemWindow::slotAddPolygonItem()
{
    QVector<QPoint>v;
    v<<QPoint(30,-15)<<QPoint(0,-30)<<QPoint(-30,-15)
    <<QPoint(-30,15)<<QPoint(0,30)<<QPoint(30,15);
    QGraphicsPolygonItem *item=new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void GraphicsItemWindow::slotAddTextItem()
{
    QFont font("Times",16);
    QGraphicsTextItem *item=new QGraphicsTextItem("Hello qt");
    item->setFont(font);
    item->setDefaultTextColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void GraphicsItemWindow::slotAddRectItem()
{
    QGraphicsRectItem *item=new QGraphicsRectItem(QRectF(0,0,60,60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setPen(pen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}
void GraphicsItemWindow::slotAddAlphaItem()
{
    QGraphicsPixmapItem *item=scene->addPixmap(QPixmap(":/res/images/image.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}

void GraphicsItemWindow::slotAddFlashItem()
{
    flashItem *item=new flashItem;
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,
                 (qrand()%int(scene->sceneRect().height()))-200);
}

void GraphicsItemWindow::slotAddStarItem()
{
    starItem *item=new starItem;
    QGraphicsItemAnimation *anim=new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *timeLine=new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);
    int y=(qrand()%400)-200;
    for (int j=0;j<400;j++) {
        anim->setPosAt(j/400.0,QPointF(j-200,y));
    }
    timeLine->start();
    scene->addItem(item);
}
