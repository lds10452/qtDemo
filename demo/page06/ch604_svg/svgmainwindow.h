#ifndef SVGMAINWINDOW_H
#define SVGMAINWINDOW_H

#include <QMainWindow>
class SvgWindow;
class SvgMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SvgMainWindow(QWidget *parent = nullptr);
    void creatMenu();
public slots:
    void slotOpenFile();
private:
    SvgWindow*svgWindow;
signals:

};

#endif // SVGMAINWINDOW_H
