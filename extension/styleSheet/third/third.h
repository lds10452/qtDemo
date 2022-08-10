#ifndef THIRD_H
#define THIRD_H

#include <QWidget>

namespace Ui {
class third;
}

class third : public QWidget
{
    Q_OBJECT

public:
    explicit third(QWidget *parent = nullptr);
    ~third();
private slots:
    void OnPushButtonClicked();
private:
    Ui::third *ui;
    bool m_bFlag;
};

#endif // THIRD_H
