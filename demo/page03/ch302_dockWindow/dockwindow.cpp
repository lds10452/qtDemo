#include "dockwindow.h"
#include <QTextEdit>
#include <QDockWidget>
DockWindow::DockWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(500,500);
    QTextEdit *text=new QTextEdit(this);
    text->setText(tr("textEdit"));
    text->setAlignment(Qt::AlignCenter);
    setCentralWidget(text);

    QDockWidget *dock=new QDockWidget(tr("dockWindow1"),this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *t1=new QTextEdit(tr("movable"));
    dock->setWidget(t1);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    dock=new QDockWidget(tr("dockWindow2"),this);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    t1=new QTextEdit(tr("close float"));
    dock->setWidget(t1);
    addDockWidget(Qt::RightDockWidgetArea,dock);

    dock=new QDockWidget(tr("dockWindow3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    t1=new QTextEdit(tr("all"));
    dock->setWidget(t1);
    addDockWidget(Qt::RightDockWidgetArea,dock);
}
