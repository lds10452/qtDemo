#include "otherdialog.h"
#include <QPushButton>
#include "drawer.h"
#include <QGridLayout>
#include "progressdialog.h"
#include "digilcdnumber.h"
#include "palettedialog.h"
#include "extensiondialog.h"
#include "shapewidget.h"
OtherDialog::OtherDialog()
{
    QGridLayout *lyout=new QGridLayout(this);
    lyout->setMargin(5);
    lyout->setSpacing(5);
    QPushButton *toolBoxBtn=new QPushButton(tr("toolbox"));
    connect(toolBoxBtn,SIGNAL(clicked()),this,SLOT(ShowToolBox()));
    lyout->addWidget(toolBoxBtn,0,0);

    QPushButton *progressBtn=new QPushButton(tr("progress"));
    connect(progressBtn,SIGNAL(clicked()),this,SLOT(ShowProgress()));
    lyout->addWidget(progressBtn,0,1);

    QPushButton *paletteBtn=new QPushButton(tr("palette"));
    connect(paletteBtn,SIGNAL(clicked()),this,SLOT(ShowPalette()));
    lyout->addWidget(paletteBtn,1,0);

    QPushButton *clockBtn=new QPushButton(tr("lcd"));
    connect(clockBtn,SIGNAL(clicked()),this,SLOT(ShowLcd()));
    lyout->addWidget(clockBtn,1,1);

    QPushButton *extBtn=new QPushButton(tr("extension"));
    connect(extBtn,SIGNAL(clicked()),this,SLOT(ShowExtension()));
    lyout->addWidget(extBtn,2,0);

    QPushButton *shapeBtn=new QPushButton(tr("shape"));
    connect(shapeBtn,SIGNAL(clicked()),this,SLOT(ShowShape()));
    lyout->addWidget(shapeBtn,2,1);
}

void OtherDialog::ShowToolBox()
{
    drawer *d=new drawer(this);
    d->setWindowModality(Qt::WindowModal);
    d->show();
}

void OtherDialog::ShowProgress()
{
    progressDialog *p=new progressDialog(this);
    p->setWindowModality(Qt::WindowModal);
    p->show();
}

void OtherDialog::ShowPalette()
{
    PaletteDialog *p=new PaletteDialog(this);
    p->setWindowModality(Qt::WindowModal);
    p->show();
}

void OtherDialog::ShowLcd()
{
    DigiLCDNumber *d=new DigiLCDNumber;
    d->setWindowModality(Qt::WindowModal);
    d->show();
}

void OtherDialog::ShowExtension()
{
    extensionDialog *e=new extensionDialog(this);
    e->setWindowModality(Qt::WindowModal);
    e->show();
}

void OtherDialog::ShowShape()
{
    shapeWidget *p=new shapeWidget;
    p->setWindowModality(Qt::WindowModal);
    p->show();
}
