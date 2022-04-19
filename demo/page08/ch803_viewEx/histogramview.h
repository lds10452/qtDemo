#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H
#include <QAbstractItemView>

class HistogramView : public QAbstractItemView
{
public:
    HistogramView();
    QRect visualRect(const QModelIndex &index)const;
    void scrollTo(const QModelIndex &index,ScrollHint hint= EnsureVisible);
    QModelIndex indexAt(const QPoint &point)const;		//(b)
    //为selections赋初值
    void setSelectionModel(QItemSelectionModel *selectionModel);
    QRegion itemRegion(QModelIndex index);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);			//(c)
protected slots:
    void selectionChanged(const QItemSelection &selected,
          const QItemSelection &deselected);			//(d)
    void dataChanged(const QModelIndex &topLeft,
          const QModelIndex &bottomRight);				//(e)
protected:
    //虚函数声明
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction,
          Qt::KeyboardModifiers modifiers);
    int horizontalOffset()const;
    int verticalOffset()const;
    bool isIndexHidden(const QModelIndex &index)const;
    void setSelection(const QRect &rect,QItemSelectionModel:: SelectionFlags flags);//(f)
    QRegion visualRegionForSelection(const QItemSelection &selection) const;
private:
    QItemSelectionModel *selections;
    QList<QRegion> MRegionList;
    QList<QRegion> FRegionList;
    QList<QRegion> SRegionList;
};

#endif // HISTOGRAMVIEW_H
