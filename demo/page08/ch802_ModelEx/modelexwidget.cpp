#include "modelexwidget.h"
#include "modelex.h"
#include <QTableView>
#include <QHBoxLayout>
ModelExWidget::ModelExWidget(QWidget *parent) : QWidget(parent)
{
    resize(500,400);
    ModelEx *model=new ModelEx;
    QTableView *view=new QTableView;
    view->setModel(model);
    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);
}
