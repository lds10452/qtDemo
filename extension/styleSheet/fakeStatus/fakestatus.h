#ifndef FAKESTATUS_H
#define FAKESTATUS_H

#include <QWidget>

namespace Ui {
class fakeStatus;
}

class fakeStatus : public QWidget
{
    Q_OBJECT

public:
    explicit fakeStatus(QWidget *parent = nullptr);
    ~fakeStatus();

private:
    Ui::fakeStatus *ui;
};

#endif // FAKESTATUS_H
