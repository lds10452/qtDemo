#ifndef FILEINFODIALOG_H
#define FILEINFODIALOG_H
#include <QDialog>
#include <QListWidgetItem>
#include <QDir>
class fileInfoDialog : public QDialog
{
    Q_OBJECT
public:
    fileInfoDialog();
private slots:
    void countDirSize();
    void showDir();
    void fileInfo();
    void fileWatcher();

private:
    qint64 du(const QString &path);//1
private slots://2
    void slotEnterShow(QDir dir=QDir("/"));
    void slotClickShow(QListWidgetItem *item);
private:
    QLineEdit *edit;
    QListWidget *widgt;
private:
    QLineEdit *fileEdit;//3
};

#endif // FILEINFODIALOG_H
