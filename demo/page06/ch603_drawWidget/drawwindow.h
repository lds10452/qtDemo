#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>
class DrawWidget;
class DrawWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit DrawWindow(QWidget *parent = nullptr);
    void creatToolBar();
public slots:
    void showStyle(int);
    void showColor();
private:
    DrawWidget *m_pDrawWgt;
    QComboBox *styleComboBox;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
signals:

};

#endif // DRAWWINDOW_H
