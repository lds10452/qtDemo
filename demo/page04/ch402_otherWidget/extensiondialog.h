#ifndef EXTENSIONDIALOG_H
#define EXTENSIONDIALOG_H
#include <QDialog>

class extensionDialog : public QDialog
{
    Q_OBJECT
public:
    extensionDialog(QWidget *p=0);
private slots:
    void showDetailInfo();
private:
    void creatBaseInfo();
    void creatDetailInfo();
    QWidget *m_pBaseWgt;
    QWidget *m_pDetailWgt;
};

#endif // EXTENSIONDIALOG_H
