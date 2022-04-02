#ifndef DIALOGEXAMPLE_H
#define DIALOGEXAMPLE_H
#include <QDialog>
class QLineEdit;
class QFrame;
class QLabel;
class DialogExample : public QDialog
{
    Q_OBJECT
public:
    DialogExample();
private:
    QLineEdit *fileEdit;
    QFrame *colorFrame;
    QLineEdit *fontLineEdit;
    QLabel *customLabel;
private slots:
    void showFile();
    void showColor();
    void showFont();
    void showInputDlg();
    void showMsgDlg();
    void showCustomDlg();
};

#endif // DIALOGEXAMPLE_H
