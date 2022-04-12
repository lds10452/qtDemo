#include "drawer.h"
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>
drawer::drawer(QWidget *p,Qt::WindowFlags f):QToolBox(p,f)
{
    //resize(200,200);
    QToolButton *btn1=new QToolButton;
    btn1->setText(tr("zhang san"));
    btn1->setIcon(QPixmap(":/res/headPic/11.png"));
    btn1->setIconSize(QPixmap(":/res/headPic/11.png").size());
    btn1->setAutoRaise(true);
    btn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QToolButton *btn2=new QToolButton;
    btn2->setText(tr("li si"));
    btn2->setIcon(QPixmap(":/res/headPic/12.png"));
    btn2->setIconSize(QPixmap(":/res/headPic/12.png").size());
    btn2->setAutoRaise(true);
    btn2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QToolButton *btn3=new QToolButton;
    btn3->setText(tr("wang wu"));
    btn3->setIcon(QPixmap(":/res/headPic/13.png"));
    btn3->setIconSize(QPixmap(":/res/headPic/13.png").size());
    btn3->setAutoRaise(true);
    btn3->setToolButtonStyle(Qt::ToolButtonFollowStyle);
    QGroupBox *group1=new QGroupBox;
    QVBoxLayout *lyout1=new QVBoxLayout(group1);
    lyout1->setMargin(10);
    lyout1->setAlignment(Qt::AlignHCenter);
    lyout1->addWidget(btn1);
    lyout1->addWidget(btn2);
    lyout1->addWidget(btn3);
    lyout1->addStretch();
    QToolButton *btn4=new QToolButton;
    btn4->setText(tr("xiao wang"));
    btn4->setIcon(QPixmap(":/res/headPic/21.png"));
    btn4->setIconSize(QPixmap(":/res/headPic/21.png").size());
    btn4->setAutoRaise(true);
    btn4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QToolButton *btn5=new QToolButton;
    btn5->setText(tr("xiao zhang"));
    btn5->setIcon(QPixmap(":/res/headPic/22.png"));
    btn5->setIconSize(QPixmap(":/res/headPic/22.png").size());
    btn5->setAutoRaise(true);
    btn5->setToolButtonStyle(Qt::ToolButtonTextOnly);
    QGroupBox *group2=new QGroupBox;
    QVBoxLayout *lyout2=new QVBoxLayout(group2);
    lyout2->setMargin(10);
    lyout2->setAlignment(Qt::AlignHCenter);
    lyout2->addWidget(btn4);
    lyout2->addWidget(btn5);
    //lyout2->addStretch();
    QToolButton *btn6=new QToolButton;
    btn6->setText(tr("xiao chen"));
    btn6->setIcon(QPixmap(":/res/headPic/31.png"));
    btn6->setIconSize(QPixmap(":/res/headPic/31.png").size());
    btn6->setAutoRaise(true);
    btn6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QToolButton *btn7=new QToolButton;
    btn7->setText(tr("xiao li"));
    btn7->setIcon(QPixmap(":/res/headPic/32.png"));
    btn7->setIconSize(QPixmap(":/res/headPic/32.png").size());
    btn7->setAutoRaise(true);
    btn7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QGroupBox *group3=new QGroupBox;
    QVBoxLayout *lyout3=new QVBoxLayout(group3);
    lyout3->setMargin(10);
    lyout3->setAlignment(Qt::AlignHCenter);
    lyout3->addWidget(btn6);
    lyout3->addWidget(btn7);
    //lyout2->addStretch();

    this->addItem((QWidget*)group1,tr("my friend"));
    this->addItem((QWidget*)group2,tr("other"));
    this->addItem((QWidget*)group3,tr("extra"));
}
