#include "httpmainwindow.h"
#include "ui_httpmainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QFileInfo>
HttpMainWindow::HttpMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HttpMainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("https://www.baidu.com")));

    ui->progressBar->hide();
}

HttpMainWindow::~HttpMainWindow()
{
    delete ui;
}

void HttpMainWindow::startRequest(QUrl url)
{
    reply=manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
}

void HttpMainWindow::replyFinished(QNetworkReply *reply)
{
    QString all = reply->readAll();
    ui->textBrowser->setText(all);
    reply->deleteLater();
}

void HttpMainWindow::httpFinished()
{
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

void HttpMainWindow::httpReadyRead()
{
    if(file)file->write(reply->readAll());
}

void HttpMainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void HttpMainWindow::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        qDebug()<<"file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
