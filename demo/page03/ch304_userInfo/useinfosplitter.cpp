#include "useinfosplitter.h"
#include "content.h"
#include <QListWidget>
UseInfoSplitter::UseInfoSplitter(QWidget *p):QSplitter(p)
{
    setOrientation(Qt::Horizontal);
    setOpaqueResize(false);
    QListWidget *list=new QListWidget(this);
    list->insertItem(0,tr("baseInfo"));
    list->insertItem(1,tr("contact"));
    list->insertItem(2,tr("detail"));
    Content *content=new Content(this);
    connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));
    setMinimumSize(this->minimumSize());
    setMaximumSize(this->maximumSize());
}
