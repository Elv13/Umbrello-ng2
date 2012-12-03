#include "diagramlistdelegate.h"

#include <QtGui/QPainter>
#include <QtCore/QDebug>
#include <QtGui/QApplication>

DiagramListDelegate::DiagramListDelegate(QObject *parent) : QAbstractItemDelegate(parent) {}

bool DiagramListDelegate::hasParent(const QModelIndex &index) const
{
    if (index.parent().isValid())
        return true;
    return false;
}

bool DiagramListDelegate::isLast(const QModelIndex &index) const
{
    if (index.parent().isValid())
        if (index.model()->rowCount(index) > index.row())
            return true;

    return false;
}

QSize DiagramListDelegate::sizeHint( const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//     if (index.model()->data(index, ExpHelper::TypeRole) == ExpHelper::Spacer)
//     return QSize(10, 10);
//     else
    if (isLast(index))
        return QSize(100, 40);
    return QSize(100, 27);
}

void DiagramListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect r = option.rect;

    // Draw the counter
    if (!index.parent().isValid()) {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing);
        QBrush br = QBrush("#222222",Qt::SolidPattern);
        painter->setBrush(br);
        painter->setPen(Qt::NoPen);
        painter->drawRect(QRect(r.x()+r.width()-28,r.y()+9,20,10));
        painter->drawEllipse(QRect(r.x()+r.width()-28-5,r.y()+9,10,10));
        painter->drawEllipse(QRect(r.x()+r.width()-5-8,r.y()+9,10,10));
        painter->setPen(QApplication::palette().base().color());
        QFont font("Arial");
        font.setBold(true);
        font.setPixelSize(8);
        painter->setFont(font);
        painter->drawText(QRect(r.x()+r.width()-28,r.y()+10,20,10), Qt::AlignCenter, QString::number(index.model()->rowCount(index)));
        painter->restore();
    }

    if (!hasParent(index)) {
        QPen pen = painter->pen();
        QFont font = painter->font();
        font.setBold(true);
        painter->setFont(font);
        pen.setColor(QColor("#dddddd"));
        painter->setPen(pen);
        painter->drawText(QRect(r.x(),r.y()+4,r.width(),r.height()-4),index.model()->data(index,0).toString());
        pen.setColor(QColor("#333333"));
        painter->setPen(pen);
        if (index.row())
            painter->drawLine(0,r.y()+1,r.width()+r.x(),r.y()+1);
    // Paint the top-item
    //} else if (isLast(index)) {
    // Paint the bottom item
    } else {
        QPen pen = painter->pen();
        pen.setColor(QColor("#AAAAAA"));
        QFont font = painter->font();
        font.setBold(false);
        painter->setFont(font);
        painter->setPen(pen);
        painter->drawText(QRect(r.x(),r.y()+4,r.width(),r.height()-4),index.model()->data(index,0).toString());
        // Paint middle items
    }

    // Draw common parts here (decoration and text)
}