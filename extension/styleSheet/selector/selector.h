#ifndef SELECTOR_H
#define SELECTOR_H

#include <QWidget>

namespace Ui {
class selector;
}

class selector : public QWidget
{
    Q_OBJECT

public:
    explicit selector(QWidget *parent = nullptr);
    ~selector();

    QString StyleSheetString(int index);
private slots:
    void ButtonClicked(int index);
private:
    Ui::selector *ui;
};

#endif // SELECTOR_H
