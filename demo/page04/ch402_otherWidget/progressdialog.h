#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H
#include <QDialog>
class QLineEdit;
class QComboBox;
class QProgressBar;
class progressDialog : public QDialog
{
    Q_OBJECT
public:
    progressDialog(QWidget *p=NULL);
private slots:
    void startProgress();
private:
    QLineEdit *fileNumLineEdit;
    QComboBox *combox;
    QProgressBar *progress;
};

#endif // PROGRESSDIALOG_H
