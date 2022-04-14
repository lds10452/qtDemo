#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
class QLabel;
class QTextEdit;
class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowWidget(QWidget *parent = nullptr);
    QLabel *imageLabel;
    QTextEdit *text;

signals:

};

#endif // SHOWWIDGET_H
