#ifndef VIEWEXMAINWINDOW_H
#define VIEWEXMAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
class ViewExMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ViewExMainWindow(QWidget *parent = nullptr);

    void createMenu();
    void setupModelView();
private:
    QStandardItemModel *model;
private slots:
    void openFile();
signals:

};

#endif // VIEWEXMAINWINDOW_H
