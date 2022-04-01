#ifndef CONTENT_H
#define CONTENT_H
#include <QFrame>
#include <QStackedWidget>
#include <QPushButton>
class BaseInfo;
class Contact;
class Detail;
class Content : public QFrame
{
    Q_OBJECT
public:
    Content(QWidget *p=NULL);
    QStackedWidget *stack;
    QPushButton *okBtn;
    QPushButton *clsBtn;
    BaseInfo *bsInfo;
    Contact *contact;
    Detail *detail;
};

#endif // CONTENT_H
