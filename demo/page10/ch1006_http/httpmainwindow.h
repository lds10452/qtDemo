#ifndef HTTPMAINWINDOW_H
#define HTTPMAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
class QFile;
class QNetworkReply;
class QNetworkAccessManager;
namespace Ui {
class HttpMainWindow;
}

class HttpMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HttpMainWindow(QWidget *parent = nullptr);
    ~HttpMainWindow();
    void startRequest(QUrl url);
private:
    Ui::HttpMainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QUrl url;
    QFile *file;
private slots:
    void replyFinished(QNetworkReply *);
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);
    void on_pushButton_clicked();
};

#endif // HTTPMAINWINDOW_H
