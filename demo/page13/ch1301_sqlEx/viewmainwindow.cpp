#include "viewmainwindow.h"
#include <QSqlRecord>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QGridLayout>
#include <QHeaderView>
#include "editdialog.h"
extern int uniqueCarId;
extern int uniqueFactoryId;
ViewMainWindow::ViewMainWindow(const QString &factoryTable,const QString &carTable,
                               QFile *carDetails,QWidget *parent) : QMainWindow(parent)
{
    file=carDetails;
    readCarData();
    carModel=new QSqlRelationalTableModel(this);
    carModel->setTable(carTable);
    carModel->setRelation(2,QSqlRelation(factoryTable,"id","manufactory"));
    carModel->select();

    factoryModel=new QSqlTableModel(this);
    factoryModel->setTable(factoryTable);
    factoryModel->select();

    QGroupBox *factory = createFactoryGroupBox();
    QGroupBox *cars = createCarGroupBox();
    QGroupBox *details = createDetailsGroupBox();
    uniqueCarId = carModel->rowCount();				//(a)
    uniqueFactoryId = factoryModel->rowCount();		//(b)
    //布局
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factory, 0, 0);
    layout->addWidget(cars, 1, 0);
    layout->addWidget(details, 0, 1, 2, 1);
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(0, 500);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    createMenuBar();
    resize(850, 400);
    setWindowTitle(tr("主从视图"));
}

void ViewMainWindow::addCar()
{
    EditDialog *dialog=new EditDialog(carModel,factoryModel,carData,file);
    int accpted=dialog->exec();
    if(accpted==1)
    {
        int lastRow=carModel->rowCount()-1;
        carView->selectRow(lastRow);
        carView->scrollToBottom();
        showCarDetails(carModel->index(lastRow,0));
    }
}

void ViewMainWindow::changeFactory(QModelIndex index)
{
    QSqlRecord record=factoryModel->record(index.row());
    QString factoryId=record.value("id").toString();
    carModel->setFilter("id='"+factoryId+"'");
    showFactoryProfile(index);
}

void ViewMainWindow::delCar()
{
    QModelIndexList selection=carView->selectionModel()->selectedRows(0);
    if(!selection.empty())
    {
        QModelIndex idIndex=selection.at(0);
        int id=idIndex.data().toInt();
        QString name=idIndex.sibling(idIndex.row(),1).data().toString();
        QString factory=idIndex.sibling(idIndex.row(),2).data().toString();
        QMessageBox::StandardButton button;
        button=QMessageBox::question(this,"delete car",tr("确认删除由%1生产的%2吗？").arg(factory).arg(name),QMessageBox::Yes|QMessageBox::No);
        if(button==QMessageBox::Yes)
        {
            removeCarFromFile(id);
            removeCarFromDatabase(idIndex);
            decreaseCarCount(indexOfFactory(factory));
        }
        else {
            QMessageBox::information(this,"删除汽车记录","请选择要删除的记录");
        }
    }
}

void ViewMainWindow::showCarDetails(QModelIndex index)
{
    QSqlRecord record=carModel->record(index.row());
    QString factory=record.value("manufactory").toString();
    QString name=record.value("name").toString();
    QString year=record.value("year").toString();
    QString carId=record.value("carid").toString();
    showFactoryProfile(indexOfFactory(factory));
    titleLabel->setText(tr("品牌：%1(%2)").arg(name).arg(year));
    titleLabel->show();
    QDomNodeList cars=carData.elementsByTagName("car");
    for (int i=0;i<cars.count();i++) {
        QDomNode car=cars.item(i);
        if(car.toElement().attribute("id")==carId)
        {
            getAttribList(car.toElement());
            break;
        }
    }
    if(!attribList->count()==0)
        attribList->show();
}

void ViewMainWindow::showFactoryProfile(QModelIndex index)
{
    QSqlRecord record=factoryModel->record(index.row());
    QString name=record.value("manufactory").toString();
    int count=carModel->rowCount();
    profileLabel->setText(tr("汽车制造商:%1\n产品数量:%2").arg(name).arg(count));
    profileLabel->show();
    titleLabel->hide();
    attribList->hide();
}

QGroupBox* ViewMainWindow::createFactoryGroupBox()
{
    factoryView = new QTableView;
    factoryView->setEditTriggers(QAbstractItemView::NoEditTriggers);
                                                            //(a)
    factoryView->setSortingEnabled(true);
    factoryView->setSelectionBehavior(QAbstractItemView::SelectRows);
    factoryView->setSelectionMode(QAbstractItemView::SingleSelection);
    factoryView->setShowGrid(false);
    factoryView->setAlternatingRowColors(true);

    factoryView->setModel(factoryModel);
    connect(factoryView,SIGNAL(clicked (QModelIndex )),this,SLOT(changeFactory(QModelIndex)));

    QGroupBox *box = new QGroupBox(tr("汽车制造商"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factoryView, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* ViewMainWindow::createCarGroupBox()
{
    QGroupBox *box = new QGroupBox(tr("汽车"));
    carView = new QTableView;
    carView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    carView->setSortingEnabled(true);
    carView->setSelectionBehavior(QAbstractItemView::SelectRows);
    carView->setSelectionMode(QAbstractItemView::SingleSelection);
    carView->setShowGrid(false);
    carView->verticalHeader()->hide();
    carView->setAlternatingRowColors(true);

    carView->setModel(carModel);
    connect(carView, SIGNAL(clicked(QModelIndex)),this,SLOT(showCarDetails(QModelIndex)));
    connect(carView, SIGNAL(activated(QModelIndex)),this,SLOT(showCarDetails(QModelIndex)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(carView, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* ViewMainWindow::createDetailsGroupBox()
{
    QGroupBox *box = new QGroupBox(tr("详细信息"));
    profileLabel = new QLabel;
    profileLabel->setWordWrap(true);
    profileLabel->setAlignment(Qt::AlignBottom);
    titleLabel = new QLabel;
    titleLabel->setWordWrap(true);
    titleLabel->setAlignment(Qt::AlignBottom);
    attribList = new QListWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(profileLabel, 0, 0, 1, 2);
    layout->addWidget(titleLabel, 1, 0, 1, 2);
    layout->addWidget(attribList, 2, 0, 1, 2);
    layout->setRowStretch(2, 1);
    box->setLayout(layout);
    return box;
}

void ViewMainWindow::createMenuBar()
{
    QAction *addAction = new QAction(tr("添加"), this);
    QAction *deleteAction = new QAction(tr("删除"), this);
    QAction *quitAction = new QAction(tr("退出"), this);
    addAction->setShortcut(tr("Ctrl+A"));
    deleteAction->setShortcut(tr("Ctrl+D"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    QMenu *fileMenu = menuBar()->addMenu(tr("操作菜单"));
    fileMenu->addAction(addAction);
    fileMenu->addAction(deleteAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    connect(addAction, SIGNAL(triggered(bool)), this, SLOT(addCar()));
    connect(deleteAction, SIGNAL(triggered(bool)), this, SLOT(delCar()));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
}

void ViewMainWindow::decreaseCarCount(QModelIndex index)
{
    int count=carModel->rowCount();
    if(count==0)
        factoryModel->removeRow(index.row());
}

void ViewMainWindow::getAttribList(QDomNode car)
{
    attribList->clear();
    QDomNodeList attribs=car.childNodes();
    for (int j=0;j<attribs.count();j++) {
        QDomNode node=attribs.item(j);
        QString attribNumber=node.toElement().attribute("number");
        QString showText(attribNumber+":"+node.toElement().text());
        QListWidgetItem *item=new QListWidgetItem(attribList);
        item->setText(tr("%1").arg(showText));
    }
}

QModelIndex ViewMainWindow::indexOfFactory(const QString &factory)
{
    for (int i=0;i<factoryModel->rowCount();i++) {
        QSqlRecord record=factoryModel->record(i);
        if(record.value("manufactory")==factory)
            return factoryModel->index(i,1);
    }
    return QModelIndex();
}

void ViewMainWindow::readCarData()
{
    if(!file->open(QIODevice::ReadOnly))
        return;
    if(!carData.setContent(file))
    {
        file->close();
        return;
    }
    file->close();
}

void ViewMainWindow::removeCarFromDatabase(QModelIndex index)
{
    carModel->revertRow(index.row());
}

void ViewMainWindow::removeCarFromFile(int id)
{
    QDomNodeList cars=carData.elementsByTagName("car");
    for (int i=0;i<cars.count();i++) {
        QDomNode node=cars.item(i);
        if(node.toElement().attribute("id").toInt()==id)
        {
            carData.elementsByTagName("archive").item(0).removeChild(node);
            break;
        }
    }
}
