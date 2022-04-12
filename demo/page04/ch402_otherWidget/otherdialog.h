#ifndef OTHERDIALOG_H
#define OTHERDIALOG_H
#include <QDialog>

class OtherDialog : public QDialog
{
    Q_OBJECT
public:
    OtherDialog();
private slots:
    void ShowToolBox();
    void ShowProgress();
    void ShowPalette();
    void ShowLcd();
    void ShowExtension();
    void ShowShape();
};

#endif // OTHERDIALOG_H
