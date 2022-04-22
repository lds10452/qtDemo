#ifndef LANGSWITCHWIDGET_H
#define LANGSWITCHWIDGET_H

#include <QWidget>
class QLabel;
class QComboBox;
class QTranslator;
class LangSwitchWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LangSwitchWidget(QWidget *parent = nullptr);
private slots:
    void changeLang(int index);
private:
    void changeTr(const QString& langCode);
    QComboBox *combox;
    QLabel *label;
    static QTranslator *translator;
signals:

};

#endif // LANGSWITCHWIDGET_H
