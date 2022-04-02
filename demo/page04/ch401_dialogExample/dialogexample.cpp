#include "dialogexample.h"
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFileDialog>
#include <QFrame>
#include <QColorDialog>
#include <QFontDialog>
#include "inputdlg.h"
#include "msgboxdlg.h"
#include <QLabel>
#include <QMessageBox>
DialogExample::DialogExample()
{
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,1);

    QPushButton *fileBtn=new QPushButton(tr("file dialog"));
    fileEdit=new QLineEdit;
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileEdit,0,1);
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));

    QPushButton *colorBtn=new QPushButton(tr("color dialog"));
    colorFrame=new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

    QPushButton *fontBtn=new QPushButton(tr("font dialog"));
    fontLineEdit=new QLineEdit(tr("welcome"));
    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));

    QPushButton *inputBtn=new QPushButton(tr("input dialog"));
    mainLayout->addWidget(inputBtn,3,0);
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));

    QPushButton *msgBtn=new QPushButton("msg dialog");
    mainLayout->addWidget(msgBtn,3,1);
    connect(msgBtn,SIGNAL(clicked()),this,SLOT(showMsgDlg()));

    QPushButton *customBtn=new QPushButton("custom dialog");
    customLabel=new QLabel;
    customLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    connect(customBtn,SIGNAL(clicked()),this,SLOT(showCustomDlg()));
    mainLayout->addWidget(customBtn,4,0);
    mainLayout->addWidget(customLabel,4,1);
}

void DialogExample::showFile()
{
    QString filePaht=QFileDialog::getOpenFileName(this,"open file","/"
              ,"c++ files(*.cpp);;c files(*.c);;head files(*.h)");
    fileEdit->setText(filePaht);
}

void DialogExample::showColor()
{
    QColor c=QColorDialog::getColor(Qt::red,this);
    if(c.isValid())
        colorFrame->setPalette(QPalette(c));
}

void DialogExample::showFont()
{
    bool ok;
    QFont f=QFontDialog::getFont(&ok);
    if(ok)
        fontLineEdit->setFont(f);
}

void DialogExample::showInputDlg()
{
    InputDlg *input=new InputDlg(this);
    input->show();
}

void DialogExample::showMsgDlg()
{
    MsgBoxDlg *msg=new MsgBoxDlg(this);
    msg->show();
}

void DialogExample::showCustomDlg()
{
    customLabel->setText("custom msg box");
    QMessageBox box;
    box.setWindowTitle("custom msg box");
    QPushButton *okBtn=box.addButton("Yes",QMessageBox::ActionRole);
    QPushButton *noBtn=box.addButton("No",QMessageBox::ActionRole);
    QPushButton *cancleBtn=box.addButton(QMessageBox::Cancel);
    box.setText("this is a custom msg box!");
    box.setIconPixmap(QPixmap(":/res/images/offest.png"));
    box.exec();
    if(box.clickedButton()==okBtn)
        customLabel->setText("custom msg box/yes");
    if(box.clickedButton()==cancleBtn)
        customLabel->setText("custom msg box/cancel");
    if(box.clickedButton()==noBtn)
        customLabel->setText("custom msg box/no");
}
