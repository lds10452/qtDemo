#include "msgboxdlg.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
MsgBoxDlg::MsgBoxDlg(QWidget *p):QDialog(p)
{
    QGridLayout *maniLayout=new QGridLayout(this);
    maniLayout->setMargin(5);
    maniLayout->setSpacing(5);

    label=new QLabel("please select msgBox:");
    maniLayout->addWidget(label,0,0,1,2);

    QPushButton *questBtn=new QPushButton("questionMsg");
    connect(questBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    maniLayout->addWidget(questBtn,1,0);

    QPushButton *informBtn=new QPushButton("informMsg");
    connect(informBtn,SIGNAL(clicked()),this,SLOT(showInformationMse()));
    maniLayout->addWidget(informBtn,1,1);

    QPushButton *warnBtn=new QPushButton("warningMsg");
    connect(warnBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    maniLayout->addWidget(warnBtn,2,0);

    QPushButton *criticalBtn=new QPushButton("criticalMsg");
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsg()));
    maniLayout->addWidget(criticalBtn,2,1);

    QPushButton *aboutBtn=new QPushButton("aboutMsg");
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    maniLayout->addWidget(aboutBtn,3,0);

    QPushButton *qtBtn=new QPushButton("aboutQtMsg");
    connect(qtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));
    maniLayout->addWidget(qtBtn,3,1);
}
void MsgBoxDlg::showQuestionMsg()
{
    label->setText("question msg box");
    switch (QMessageBox::question(this,"question box","finish ,exit?",
    QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel)) {
    case QMessageBox::Ok:
        label->setText("question button/ok");
        break;
    case QMessageBox::Cancel:
        label->setText("question button/cancel");
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showInformationMse()
{
    label->setText("information message box");
    QMessageBox::information(this,"information box",
               "this is information box");
    return;
}
void MsgBoxDlg::showWarningMsg()
{
    label->setText("warning msg box");
    switch (QMessageBox::warning(this,"warning box","not save,save modify?",
      QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Cancel)) {
    case QMessageBox::Save:
        label->setText("warning button/save");
        break;
    case QMessageBox::Discard:
        label->setText("warning button/discard");
        break;
    case QMessageBox::Cancel:
        label->setText("warning button/cancel");
        break;
    default:
        break;
    }
}
void MsgBoxDlg::showCriticalMsg()
{
    label->setText("critiacl msg box");
    QMessageBox::critical(this,"critical box","this is a critical box");
}
void MsgBoxDlg::showAboutMsg()
{
    label->setText("about msg box");
    QMessageBox::about(this,"about box","this is a about box");
}
void MsgBoxDlg::showAboutQtMsg()
{
    label->setText("about qt box");
    QMessageBox::aboutQt(this,"about qt box");
}
