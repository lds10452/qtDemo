#ifndef NETWORKINFOWGT_H
#define NETWORKINFOWGT_H

#include <QWidget>
class QPushButton;
class QLineEdit;
class NetWorkInfoWgt : public QWidget
{
    Q_OBJECT
public:
    explicit NetWorkInfoWgt(QWidget *parent = nullptr);
private:
    QPushButton *btn;
    QLineEdit *hostLineEdit;
    QLineEdit *ipLineEdit;
    void ShowDeviceInfo();
private slots:
    void ShowDetial();
signals:

};

#endif // NETWORKINFOWGT_H
