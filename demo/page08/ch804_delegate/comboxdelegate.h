#ifndef COMBOXDELEGATE_H
#define COMBOXDELEGATE_H
#include <QItemDelegate>

class ComboxDelegate : public QItemDelegate
{
public:
    ComboxDelegate();
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // COMBOXDELEGATE_H
