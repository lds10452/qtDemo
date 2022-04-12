#include "progressdialog.h"
#include <QFont>
#include <QProgressDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressDialog>
progressDialog::progressDialog(QWidget *p):QDialog(p)
{
    QFont font("ZYSong18030",12);
    setFont(font);
    QLabel *fileNum=new QLabel(tr("file num:"));
    fileNumLineEdit=new QLineEdit(tr("100000"));
    QLabel *typeLabel=new QLabel(tr("type:"));
    combox=new QComboBox;
    combox->addItem(tr("prgressBar"));
    combox->addItem(tr("progressDialog"));
    progress=new QProgressBar;
    QPushButton *startBtn=new QPushButton(tr("start"));
    QGridLayout *layout=new QGridLayout(this);
    layout->addWidget(fileNum,0,0);
    layout->addWidget(fileNumLineEdit,0,1);
    layout->addWidget(typeLabel,1,0);
    layout->addWidget(combox,1,1);
    layout->addWidget(progress,2,0,1,2);
    layout->addWidget(startBtn,3,1);
    layout->setMargin(15);
    layout->setSpacing(10);
    connect(startBtn,SIGNAL(clicked()),this,SLOT(startProgress()));
}

void progressDialog::startProgress()
{
    int num=fileNumLineEdit->text().toInt();
    if(combox->currentIndex()==0)
    {
        progress->setRange(0,num);
        for (int i=1;i<num+1;i++) {
            progress->setValue(i);
        }
    }
    else if(combox->currentIndex()==1)
    {
        QProgressDialog *p=new QProgressDialog(this);
        QFont font("ZYSong18030",12);
        p->setFont(font);
        p->setWindowModality(Qt::WindowModal);
        p->setMinimumDuration(5);
        p->setLabelText(tr("copying"));
        p->setCancelButtonText(tr("cancel"));
        p->setRange(0,num);
        for (int i=0;i<num;i++) {
            p->setValue(i);
            if(p->wasCanceled())
                return;
        }
    }
}
