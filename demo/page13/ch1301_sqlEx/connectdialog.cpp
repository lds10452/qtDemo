#include "connectdialog.h"
#include "ui_connectdialog.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QComboBox>
#include "viewmainwindow.h"
connectDialog::connectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectDialog)
{
    ui->setupUi(this);
    QStringList drivers=QSqlDatabase::drivers();
    ui->comboDriver_2->addItems(drivers);
    connect(ui->comboDriver_2,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(driverChanged(const QString &)));
    driverChanged(ui->comboDriver_2->currentText());
    ui->status_label_2->setText("准备连接数据库！");
}

connectDialog::~connectDialog()
{
    delete ui;
}

QSqlError connectDialog::addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port)
{
    QSqlError err;
    QSqlDatabase db=QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if(!db.open(user,passwd))
    {
        err=db.lastError();
    }
    return err;
}

void connectDialog::addSpliteConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../demo/res/dataBase/databasefile");
    if(!db.open())
    {
        ui->status_label_2->setText(db.lastError().text());
        return;
    }
    ui->status_label_2->setText("创建数据库成功！");
}

void connectDialog::createDB()
{
    QSqlQuery query;                                    //(a)
    query.exec("create table factory (id int primary key,manufactory varchar(40), address varchar(40))");				//(b)
    query.exec(QObject::tr("insert into factory values(1, '一汽大众', '长春')"));
    query.exec(QObject::tr("insert into factory values(2, '二汽神龙', '武汉')"));
    query.exec(QObject::tr("insert into factory values(3, '上海大众', '上海')"));
    query.exec("create table cars (carid int primary key, name varchar(50), factoryid int, year int, foreign key(factoryid) references factory(id))");	//(c)
    query.exec(QObject::tr("insert into cars values(1,'奥迪A6',1,2005)"));
    query.exec(QObject::tr("insert into cars values(2, '捷达', 1, 1993)"));
    query.exec(QObject::tr("insert into cars values(3, '宝来', 1, 2000)"));
    query.exec(QObject::tr("insert into cars values(4, '毕加索',2, 1999)"));
    query.exec(QObject::tr("insert into cars values(5, '富康', 2, 2004)"));
    query.exec(QObject::tr("insert into cars values(6, '标致307',2, 2001)"));
    query.exec(QObject::tr("insert into cars values(7, '桑塔纳',3, 1995)"));
    query.exec(QObject::tr("insert into cars values(8, '帕萨特',3, 2000)"));
}

void connectDialog::driverChanged(const QString &text)
{
    if(text=="QSQLITE")
    {
        ui->editDatabase_2->setEnabled(false);
        ui->editHostname_2->setEnabled(false);
        ui->editPassword_2->setEnabled(false);
        ui->editUsername_2->setEnabled(false);
        ui->portSpinBox_2->setEnabled(false);
    }
    else {
        ui->editDatabase_2->setEnabled(true);
        ui->editHostname_2->setEnabled(true);
        ui->editPassword_2->setEnabled(true);
        ui->editUsername_2->setEnabled(true);
        ui->portSpinBox_2->setEnabled(true);
    }
}

void connectDialog::on_okButton_2_clicked()
{
    if(ui->comboDriver_2->currentText().isEmpty())
    {
        ui->status_label_2->setText("请选择一个数据库驱动！");
        ui->comboDriver_2->setFocus();
    }
    else if (ui->comboDriver_2->currentText()=="QSQLITE") {
        addSpliteConnection();
        createDB();
    }
    else {
        QSqlError err=addConnection(ui->comboDriver_2->currentText(),ui->editDatabase_2->text(),ui->editHostname_2->text(),
                      ui->editUsername_2->text(),ui->editPassword_2->text(),ui->portSpinBox_2->text().toInt());
        if(err.type()!=QSqlError::NoError)
        {
            ui->status_label_2->setText(err.text());
        }
        else {
            ui->status_label_2->setText("选择数据库成功！");
            createDB();
        }
    }
    QFile *carDetails = new QFile("../demo/res/dataBase/attribs.xml");
    ViewMainWindow *view=new ViewMainWindow("factory", "cars", carDetails);
    view->setWindowModality(Qt::WindowModal);
    view->show();
    this->close();
}

void connectDialog::on_cancelButton_2_clicked()
{
    reject();
}
