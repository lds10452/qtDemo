#include "svgmainwindow.h"
#include "SvgWindow.h"
#include <QMenuBar>
#include <QFileDialog>
SvgMainWindow::SvgMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("svg viewer"));
    creatMenu();
    svgWindow=new SvgWindow;
    setCentralWidget(svgWindow);
}
void SvgMainWindow::creatMenu()
{
    QMenu*fileMenu=menuBar()->addMenu(tr("文件"));
    QAction *openAct=new QAction(tr("打开"),this);
    connect(openAct,SIGNAL(triggered()),this,SLOT(slotOpenFile()));
    fileMenu->addAction(openAct);
}
void SvgMainWindow::slotOpenFile()
{
    QString name=QFileDialog::getOpenFileName(this,"打开","../demo/","svg files(*.svg)");
    svgWindow->setFile(name);
}
