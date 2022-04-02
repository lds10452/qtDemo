#include "inputdlg.h"
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QInputDialog>
InputDlg::InputDlg(QWidget *p):QDialog(p)
{
    setWindowTitle(tr("input dialog"));
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,2);
    mainLayout->setColumnStretch(3,1);

    QLabel *nameLabel=new QLabel(tr("name:"));
    newName=new QLabel(tr("xiao he"));
    newName->setFrameStyle(QFrame::Panel|QFrame::Raised);
    QPushButton *nameBtn=new QPushButton(tr("change name"));
    connect(nameBtn,SIGNAL(clicked()),this,SLOT(changeName()));
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(newName,0,1,1,2);
    mainLayout->addWidget(nameBtn,0,3);

    QLabel *sexLabel=new QLabel("sex:");
    newSex=new QLabel("man");
    newSex->setFrameStyle(QFrame::Panel|QFrame::Raised);
    QPushButton *sexBtn=new QPushButton("change sex");
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(changeSex()));
    mainLayout->addWidget(sexLabel,1,0);
    mainLayout->addWidget(newSex,1,1,1,2);
    mainLayout->addWidget(sexBtn,1,3);

    QLabel *ageLabel=new QLabel("age:");
    newAge=new QLabel("20");
    newAge->setFrameStyle(QFrame::Panel|QFrame::Raised);
    QPushButton *ageBtn=new QPushButton("change age");
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(changeAge()));
    mainLayout->addWidget(ageLabel,2,0);
    mainLayout->addWidget(newAge,2,1,1,2);
    mainLayout->addWidget(ageBtn,2,3);

    QLabel *scoreLabel=new QLabel("score:");
    newScore=new QLabel("80");
    newScore->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    QPushButton *scoreBtn=new QPushButton("change score");
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(changeScore()));
    mainLayout->addWidget(scoreLabel,3,0);
    mainLayout->addWidget(newScore,3,1,1,2);
    mainLayout->addWidget(scoreBtn,3,3);
}

void InputDlg::changeName()
{
    bool ok;
    QString text=QInputDialog::getText(this,"string input",
            "please input name:",QLineEdit::Normal,newName->text(),&ok);
    if(ok&&!text.isEmpty())
        newName->setText(text);
}

void InputDlg::changeSex()
{
    QStringList item;
    item<<"man"<<"woman";
    bool ok;
    QString sex=QInputDialog::getItem(this,"select item","please select sex:",
                 item,1,false,&ok);
    if(ok&&!sex.isEmpty())
        newSex->setText(sex);
}

void InputDlg::changeAge()
{
    bool ok;
    int age=QInputDialog::getInt(this,"int input","please input age:",
               newAge->text().toInt(&ok),0,100,1,&ok);
    if(ok)
        newAge->setText(tr("%1").arg(age));
}

void InputDlg::changeScore()
{
    bool ok;
    double score=QInputDialog::getDouble(this,"double input","please input score:",
                 newScore->text().toDouble(&ok),0,100,1,&ok);
    if(ok)
        newScore->setText(tr("%1").arg(score));
}
