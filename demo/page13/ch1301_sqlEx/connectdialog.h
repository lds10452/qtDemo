#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
class QSqlError;
namespace Ui {
class connectDialog;
}

class connectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectDialog(QWidget *parent = nullptr);
    ~connectDialog();
    QSqlError addConnection(const QString &driver,const QString &dbName,const QString &host,
                            const QString &user,const QString &passwd,int port=-1);
    void addSpliteConnection();
    void createDB();
private slots:
    void driverChanged(const QString &);
    void on_okButton_2_clicked();

    void on_cancelButton_2_clicked();

private:
    Ui::connectDialog *ui;
};

#endif // CONNECTDIALOG_H
