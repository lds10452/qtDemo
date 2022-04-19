#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H
#include <QItemDelegate>

class DateDelegate : public QItemDelegate
{
public:
    DateDelegate(QObject *p=0);
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // DATEDELEGATE_H
