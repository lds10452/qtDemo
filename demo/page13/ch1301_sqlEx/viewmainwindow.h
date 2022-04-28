#ifndef VIEWMAINWINDOW_H
#define VIEWMAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDomNode>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QTableView>
#include <QListWidget>
#include <QLabel>
class ViewMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ViewMainWindow(const QString &factoryTable,const QString &carTable,
             QFile *carDetails, QWidget *parent = nullptr);
private slots:
    void addCar();
    void changeFactory(QModelIndex index);
    void delCar();
    void showCarDetails(QModelIndex index);
    void showFactoryProfile(QModelIndex index);
private:
    QGroupBox *createCarGroupBox();
    QGroupBox *createFactoryGroupBox();
    QGroupBox *createDetailsGroupBox();
    void createMenuBar();
    QTableView *carView;						//(a)
    QTableView *factoryView;					//(b)
    QListWidget *attribList;					//显示车型的详细信息列表
    /* 声明相关的信息标签 */
    QLabel *profileLabel;
    QLabel *titleLabel;
    void decreaseCarCount(QModelIndex index);
    void getAttribList(QDomNode car);
    QModelIndex indexOfFactory(const QString &factory);
    void readCarData();
    void removeCarFromDatabase(QModelIndex index);
    void removeCarFromFile(int id);

    QDomDocument carData;
    QFile *file;
    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;
signals:

};

#endif // VIEWMAINWINDOW_H
