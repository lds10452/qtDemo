#include <QApplication>
#include <QSplashScreen>
#include <QMovie>
#include "page01/ch101_designCal/designcaldialog.h"
#include "page01/ch102_calArea/caldialog.h"
#include "page02/ch208_itemWidget/itemwidget.h"
#include "page03/ch301_splitterWidget/splitterwidget.h"
#include "page03/ch302_dockWindow/dockwindow.h"
#include "page03/ch303_stackDialog/stackdialog.h"
#include "page03/ch304_userInfo/useinfosplitter.h"
#include "page04/ch401_dialogExample/dialogexample.h"
#include "page04/ch402_otherWidget/otherdialog.h"
#include "page05/ImgEditMainWindow/imgeditmainwindow.h"
#include "page06/ch601_geometry/geometry.h"
#include "page06/ch602_paintEx/mainwidget.h"
#include "page06/ch603_drawWidget/drawwindow.h"
#include "page06/ch604_svg/svgmainwindow.h"
#include "page07/ch701_butterfly/butterflywidget.h"
#include "page07/ch702_map/mapwidget.h"
#include "page07/ch703_item/graphicsitemwindow.h"
#include "page07/ch704_transform/transformwidget.h"
#include "page08/ch801_dirModelEx/dirmodel.h"
#include "page08/ch802_ModelEx/modelexwidget.h"
#include "page08/ch803_viewEx/viewexmainwindow.h"
#include "page08/ch804_delegate/delegatedialog.h"
#include "page09/ch901_rwFile/rwfiledialog.h"
#include "page09/ch902_fileInfo/fileinfodialog.h"
#include "page11/ch1101_mouseEvent/mouseeventmainwindow.h"
#include "page11/ch1102_eventFilter/eventfilterdialog.h"
#include "page11/ch1103_keyEvent/keyeventdialog.h"
#include "page14/ch1401_multiLang/multilangwidget.h"
#include "page14/ch1402_langSwitch/langswitchwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("ZYSong18030",12);
    a.setFont(f);
    QPixmap pix;
    pix.load(":/res/images/icon.png");
    QSplashScreen splash(pix);
    splash.showMessage("Loading!!!!!!!!",Qt::AlignHCenter);
    QLabel label(&splash);
    label.resize(pix.size());
    QMovie mv(":/res/gif/orange.gif");
    label.setMovie(&mv);
    mv.start();
    splash.show();
    for(int i=0;i<50;i++)
    {
        a.processEvents();
        _sleep(1);
    }
    QWidget*m_pWgt=NULL;
    //m_pWgt=new designCalDialog;//1
    //m_pWgt=new calDialog;
    //m_pWgt=new ItemWidget;//2
    //m_pWgt=new SplitterWidget;//3
    //m_pWgt=new DockWindow;
    //m_pWgt=new StackDialog;
    //m_pWgt=new UseInfoSplitter;
    //m_pWgt=new DialogExample;//4
    //m_pWgt=new OtherDialog;
    //m_pWgt=new ImgEditMainWindow;//5
    //m_pWgt=new Geometry;//6
    //m_pWgt=new MainWidget;
    //m_pWgt=new DrawWindow;
    //m_pWgt=new SvgMainWindow;
    //m_pWgt=new ButterflyWidget;//7
    //m_pWgt=new MapWidget;
    //m_pWgt=new GraphicsItemWindow;
    //m_pWgt=new transFormWidget;
    //m_pWgt=new DirModel;//8
    //m_pWgt=new ModelExWidget;
    //m_pWgt=new ViewExMainWindow;
    //m_pWgt=new DelegateDialog;
    //m_pWgt=new RwFileDialog;//9
    //m_pWgt=new fileInfoDialog;
    //m_pWgt=new mouseEventMainWindow;//11
    //m_pWgt=new eventFilterDialog;
    //m_pWgt=new KeyEventDialog;
    //m_pWgt=new MultiLangWidget;//14
    m_pWgt=new LangSwitchWidget;
    m_pWgt->show();
    splash.finish(m_pWgt);
    return a.exec();
}

