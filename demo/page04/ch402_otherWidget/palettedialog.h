#ifndef PALETTEDIALOG_H
#define PALETTEDIALOG_H
#include <QDialog>
#include <QComboBox>
#include <QFrame>
class PaletteDialog : public QDialog
{
    Q_OBJECT
public:
    PaletteDialog(QWidget *p=NULL);
    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox*);
private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();
private:
    QFrame *m_pContentFrame;
    QFrame *m_pCtrlFrame;
    QComboBox *windowCombox;
    QComboBox *windowTextCombox;
    QComboBox *buttonCombox;
    QComboBox *buttonTextCombox;
    QComboBox *baseCombox;
};

#endif // PALETTEDIALOG_H
