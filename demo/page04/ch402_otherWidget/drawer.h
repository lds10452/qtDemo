#ifndef DRAWER_H
#define DRAWER_H
#include <QToolBox>

class drawer : public QToolBox
{
    //Q_OBJECT
public:
    drawer(QWidget *p=NULL,Qt::WindowFlags f=Qt::Dialog);
};

#endif // DRAWER_H
