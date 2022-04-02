#ifndef INPUTDLG_H
#define INPUTDLG_H
#include <QDialog>
class QLabel;

class InputDlg : public QDialog
{
    Q_OBJECT
public:
    InputDlg(QWidget *p=0);
private slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeScore();
private:
    QLabel *newName;
    QLabel *newSex;
    QLabel *newAge;
    QLabel *newScore;
};

#endif // INPUTDLG_H
