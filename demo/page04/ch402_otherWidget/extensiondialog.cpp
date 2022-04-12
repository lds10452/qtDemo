#include "extensiondialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>
extensionDialog::extensionDialog(QWidget *p):QDialog(p)
{
    creatBaseInfo();
    creatDetailInfo();
    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(m_pBaseWgt);
    mainLayout->addWidget(m_pDetailWgt);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->setSpacing(10);
}

void extensionDialog::showDetailInfo()
{
    if(m_pDetailWgt->isHidden())
        m_pDetailWgt->show();
    else
        m_pDetailWgt->hide();
}

void extensionDialog::creatBaseInfo()
{
    m_pBaseWgt =new QWidget;
    QLabel *nameLabel =new QLabel(tr("姓名："));
    QLineEdit *nameLineEdit =new QLineEdit;
    QLabel *sexLabel =new QLabel(tr("性别："));
    QComboBox *sexComboBox =new  QComboBox;
    sexComboBox->insertItem(0,tr("女"));
    sexComboBox->insertItem(1,tr("男"));
    QGridLayout *LeftLayout =new QGridLayout;
    LeftLayout->addWidget(nameLabel,0,0);
    LeftLayout->addWidget(nameLineEdit,0,1);
    LeftLayout->addWidget(sexLabel);
    LeftLayout->addWidget(sexComboBox);
    QPushButton *OKBtn =new QPushButton(tr("确定"));
    QPushButton *DetailBtn =new QPushButton(tr("详细"));
    QDialogButtonBox *btnBox=new QDialogButtonBox(Qt::Vertical);
    btnBox->addButton(OKBtn,QDialogButtonBox::ActionRole);
    btnBox->addButton(DetailBtn,QDialogButtonBox::ActionRole);
    QHBoxLayout *mainLayout =new QHBoxLayout(m_pBaseWgt);
    mainLayout->addLayout(LeftLayout);
    mainLayout->addWidget(btnBox);
    connect(DetailBtn,SIGNAL(clicked()),this,SLOT(showDetailInfo()));
}

void extensionDialog::creatDetailInfo()
{
    m_pDetailWgt =new QWidget;
    QLabel *ageLabel =new QLabel(tr("年龄："));
    QLineEdit *ageLineEdit =new QLineEdit;
    ageLineEdit->setText(tr("30"));
    QLabel *departmentLabel =new QLabel(tr("部门："));
    QComboBox *departmentComBox =new QComboBox;
    departmentComBox->addItem(tr("部门1"));
    departmentComBox->addItem(tr("部门2"));
    departmentComBox->addItem(tr("部门3"));
    departmentComBox->addItem(tr("部门4"));
    QLabel *emailLabel =new QLabel(tr("email："));
    QLineEdit *emailLineEdit =new QLineEdit;
    QGridLayout *mainLayout =new QGridLayout(m_pDetailWgt);
    mainLayout->addWidget(ageLabel,0,0);
    mainLayout->addWidget(ageLineEdit,0,1);
    mainLayout->addWidget(departmentLabel,1,0);
    mainLayout->addWidget(departmentComBox,1,1);
    mainLayout->addWidget(emailLabel,2,0);
    mainLayout->addWidget(emailLineEdit,2,1);
    m_pDetailWgt->hide();
}
