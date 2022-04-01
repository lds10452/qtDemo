#include "content.h"
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
Content::Content(QWidget *p):QFrame(p)
{
    stack=new QStackedWidget;
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    bsInfo=new BaseInfo;
    contact=new Contact;
    detail=new Detail;
    stack->addWidget(bsInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    okBtn=new QPushButton(tr("modify"));
    clsBtn=new QPushButton(tr("close"));
    QHBoxLayout *lyout=new QHBoxLayout;
    lyout->addStretch();//占位符，使两个按钮
    lyout->addWidget(okBtn);
    lyout->addWidget(clsBtn);

    QVBoxLayout *vlyout=new QVBoxLayout(this);
    vlyout->setMargin(10);
    vlyout->setSpacing(6);
    vlyout->addWidget(stack);
    vlyout->addLayout(lyout);
}
