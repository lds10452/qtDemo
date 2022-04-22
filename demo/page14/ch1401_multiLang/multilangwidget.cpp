#include "multilangwidget.h"
#include "ui_multilangwidget.h"
#include <QTranslator>
MultiLangWidget::MultiLangWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiLangWidget)
{
    QTranslator *tr=new QTranslator;
    tr->load(":/res/langFile/MultiLangWidget.qm");
    qApp->installTranslator(tr);
    ui->setupUi(this);
}

MultiLangWidget::~MultiLangWidget()
{
    delete ui;
}
