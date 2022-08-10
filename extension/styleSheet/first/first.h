#ifndef FIRST_H
#define FIRST_H

#include <QWidget>

namespace Ui {
class first;
}

class first : public QWidget
{
    Q_OBJECT

public:
    explicit first(QWidget *parent = nullptr);
    ~first();

private:
    Ui::first *ui;
};

#endif // FIRST_H
