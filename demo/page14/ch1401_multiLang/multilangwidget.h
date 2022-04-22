#ifndef MULTILANGWIDGET_H
#define MULTILANGWIDGET_H

#include <QWidget>

namespace Ui {
class MultiLangWidget;
}

class MultiLangWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MultiLangWidget(QWidget *parent = nullptr);
    ~MultiLangWidget();

private:
    Ui::MultiLangWidget *ui;
};

#endif // MULTILANGWIDGET_H
