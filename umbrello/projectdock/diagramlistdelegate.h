#ifndef DIAGRAM_LIST_DELEGATE_H
#define DIAGRAM_LIST_DELEGATE_H

#include <QtGui/QAbstractItemDelegate>

class DiagramListDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    DiagramListDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    bool hasParent(const QModelIndex &index) const;
    bool isLast(const QModelIndex &index) const;
};

#endif