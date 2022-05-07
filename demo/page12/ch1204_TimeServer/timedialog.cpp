#include "timedialog.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "timeserver.h"
#include <QMessageBox>
TimeDialog::TimeDialog(QWidget *p):QDialog(p)
{
    QLabel *label=new QLabel("port:");
    countLabel=new QLabel;
    QPushButton *btn=new QPushButton("close");
    QHBoxLayout *hLayout=new QHBoxLayout;
    hLayout->addStretch(1);
    hLayout->addWidget(btn);
    hLayout->addStretch(1);
    QVBoxLayout *vLayout=new QVBoxLayout(this);
    vLayout->addWidget(label);
    vLayout->addWidget(countLabel);
    vLayout->addLayout(hLayout);
    connect(btn,&QPushButton::clicked,this,&TimeDialog::close);
    count=0;
    timerServer=new TimeServer(this);
    if(!timerServer->listen())
    {
        QMessageBox::critical(this,"server thread",tr("can't start server:%1").arg(timerServer->errorString()));
        close();
        return;
    }
    label->setText(tr("port:%1").arg(timerServer->serverPort()));
}

void TimeDialog::slotShow()
{
    countLabel->setText(tr("NO.%1 request finished").arg(++count));
}
