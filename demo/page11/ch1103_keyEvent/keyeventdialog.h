#ifndef KEYEVENTDIALOG_H
#define KEYEVENTDIALOG_H
#include <QDialog>
class QPixmap;
//class QImage;
class KeyEventDialog : public QDialog
{
public:
    KeyEventDialog();
    void drawPix();
    void keyPressEvent(QKeyEvent *) override;
    void paintEvent(QPaintEvent *) override;
private:
    QPixmap *pix;
    QPixmap img;
    int startX;
    int startY;
    int width;
    int height;
    int step;
};

#endif // KEYEVENTDIALOG_H
