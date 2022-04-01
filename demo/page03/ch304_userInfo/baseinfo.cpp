#include "baseinfo.h"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
    QLabel *userNameLabel=new QLabel(tr("userName:"));
    QLineEdit *useNameLineEdit=new QLineEdit;
    QLabel *nameLabel=new QLabel(tr("name:"));
    QLineEdit *nameLineEdit=new QLineEdit;
    QLabel *sexLabel=new QLabel(tr("sex:"));
    QComboBox *sexCombox=new QComboBox;
    sexCombox->addItem(tr("man"));
    sexCombox->addItem(tr("woman"));
    QLabel *departMentLabel=new QLabel(tr("department:"));
    QTextEdit *departMentText=new QTextEdit;
    QLabel *ageLabel=new QLabel(tr("age:"));
    QLineEdit *ageLineEdit=new QLineEdit;
    QLabel *otherLabel=new QLabel(tr("other:"));
    otherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    QGridLayout *left=new QGridLayout;
    left->addWidget(userNameLabel,0,0);
    left->addWidget(useNameLineEdit,0,1);
    left->addWidget(nameLabel,1,0);
    left->addWidget(nameLineEdit,1,1);
    left->addWidget(sexLabel,2,0);
    left->addWidget(sexCombox,2,1);
    left->addWidget(departMentLabel,3,0);
    left->addWidget(departMentText,3,1);
    left->addWidget(ageLabel,4,0);
    left->addWidget(ageLineEdit,4,1);
    left->addWidget(otherLabel,5,0,1,2);
    left->setColumnStretch(0,1);
    left->setColumnStretch(1,3);

    QLabel *headLabel=new QLabel(tr("head:"));
    QLabel *headIcon=new QLabel;
    QPixmap pix(":/res/images/star.png");
    headIcon->setPixmap(pix);
    headIcon->resize(pix.size());
    QPushButton *btn=new QPushButton(tr("update"));
    QHBoxLayout *topRightlyout=new QHBoxLayout;
    topRightlyout->setSpacing(20);
    topRightlyout->addWidget(headLabel);
    topRightlyout->addWidget(headIcon);
    topRightlyout->addWidget(btn);
    QLabel *introductionLabel=new QLabel(tr("introduction:"));
    QTextEdit *introductionTextedit=new QTextEdit;
    QVBoxLayout *rlyout=new QVBoxLayout;
    rlyout->setMargin(10);
    rlyout->addLayout(topRightlyout);
    rlyout->addWidget(introductionLabel);
    rlyout->addWidget(introductionTextedit);

    QGridLayout *mainLyout=new QGridLayout(this);
    mainLyout->setMargin(15);
    mainLyout->setSpacing(10);
    mainLyout->addLayout(left,0,0);
    mainLyout->addLayout(rlyout,0,1);
}
