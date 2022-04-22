#ifndef MOUSEEVENTMAINWINDOW_H
#define MOUSEEVENTMAINWINDOW_H

#include <QMainWindow>
class QLabel;
class mouseEventMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mouseEventMainWindow(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
private:
    QLabel *mousePos;
signals:

};

#endif // MOUSEEVENTMAINWINDOW_H
