#include <QApplication>
#include "page01/ch101_designCal/designcaldialog.h"
#include "page01/ch102_calArea/caldialog.h"
#include "page02/ch208_itemWidget/itemwidget.h"
#include "page03/ch301_splitterWidget/splitterwidget.h"
#include "page03/ch302_dockWindow/dockwindow.h"
#include "page06/ch601_geometry/geometry.h"
#include "page06/ch602_paintEx/mainwidget.h"
#include "page06/ch603_drawWidget/drawwindow.h"
#include "page06/ch604_svg/svgmainwindow.h"
#include "page07/ch702_map/mapwidget.h"
#include "page07/ch703_item/graphicsitemwindow.h"
#include "page07/ch704_transform/transformwidget.h"
#include "page08/ch801_dirModelEx/dirmodel.h"
#include "page08/ch802_ModelEx/modelexwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("ZYSong18030",12);
    a.setFont(f);
    QWidget*m_pWgt=NULL;
    //m_pWgt=new designCalDialog;//1
    //m_pWgt=new calDialog;
    //m_pWgt=new ItemWidget;//2
    //m_pWgt=new SplitterWidget;//3
    m_pWgt=new DockWindow;
    //m_pWgt=new Geometry;//6
    //m_pWgt=new MainWidget;
    //m_pWgt=new DrawWindow;
    //m_pWgt=new SvgMainWindow;

    //m_pWgt=new MapWidget;//7
    //m_pWgt=new GraphicsItemWindow;
    //m_pWgt=new transFormWidget;

    //m_pWgt=new DirModel;//8
    //m_pWgt=new ModelExWidget;
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
