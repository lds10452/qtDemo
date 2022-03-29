#ifndef CALDIALOG_H
#define CALDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class calDialog : public QWidget
{
    Q_OBJECT
public:
    explicit calDialog(QWidget *parent = nullptr);
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton *button;
public slots:
    void showArea();
signals:

};

#endif // CALDIALOG_H
