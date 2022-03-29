#ifndef DESIGNCALDIALOG_H
#define DESIGNCALDIALOG_H

#include <QWidget>

namespace Ui {
class designCalDialog;
}

class designCalDialog : public QWidget
{
    Q_OBJECT

public:
    explicit designCalDialog(QWidget *parent = nullptr);
    ~designCalDialog();

private slots:
    void on_countBtn_clicked();

    void on_radiusLineEdit_textEdited(const QString &arg1);

private:
    Ui::designCalDialog *ui;
};

#endif // DESIGNCALDIALOG_H
