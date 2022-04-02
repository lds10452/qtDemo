#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H
#include <QDialog>
class QLabel;
class MsgBoxDlg : public QDialog
{
    Q_OBJECT
public:
    MsgBoxDlg(QWidget *p=0);
    QLabel *label;
private slots:
    void showQuestionMsg();
    void showInformationMse();
    void showWarningMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();
};

#endif // MSGBOXDLG_H
