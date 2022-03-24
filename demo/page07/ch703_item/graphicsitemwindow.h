#ifndef GRAPHICSITEMWINDOW_H
#define GRAPHICSITEMWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
class GraphicsItemWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GraphicsItemWindow(QWidget *parent = nullptr);
    void createMenu();
    void initScene();

public slots:
    void slotNew();
    void slotClear();
    void slotAddEllipseItem();
    void slotAddPolygonItem();
    void slotAddTextItem();
    void slotAddRectItem();
    void slotAddAlphaItem();
    void slotAddFlashItem();
    void slotAddStarItem();
private:
    QGraphicsScene *scene;

signals:

};

#endif // GRAPHICSITEMWINDOW_H
