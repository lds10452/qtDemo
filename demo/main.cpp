#include <QApplication>
#include "page06/ch601_geometry/geometry.h"
#include "page06/ch602_paintEx/mainwidget.h"
#include "page06/ch603_drawWidget/drawwindow.h"
#include "page06/ch604_svg/svgmainwindow.h"
#include "page07/ch702_map/mapwidget.h"
#include "page07/ch703_item/graphicsitemwindow.h"
#include "page07/ch704_transform/transformwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("ZYSong18030",12);
    a.setFont(f);
    QWidget*m_pWgt=NULL;
    //m_pWgt=new Geometry;//6
    //m_pWgt=new MainWidget;
    //m_pWgt=new DrawWindow;
    //m_pWgt=new SvgMainWindow;

    //m_pWgt=new MapWidget;//7
    //m_pWgt=new GraphicsItemWindow;
    m_pWgt=new transFormWidget;
    m_pWgt->show();
    return a.exec();
}

#include "page07/ch701_butterfly/butterfly.h"
#include <QGraphicsScene>
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QGraphicsScene *scene=new QGraphicsScene;
//    scene->setSceneRect(QRectF(-200,-200,400,400));
//    butterFly *butter=new butterFly;
//    butter->setPos(-100,0);
//    scene->addItem(butter);
//    QGraphicsView *view=new QGraphicsView;
//    view->setScene(scene);
//    view->resize(400,400);
//    view->show();
//    return a.exec();
//}
