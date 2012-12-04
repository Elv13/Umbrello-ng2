#include "delegatewidgetbase.h"

#include <QtCore/QDebug>

DelegateWidgetBase::DelegateWidgetBase(const QModelIndex& index, QWidget* parent) : QWidget(parent),m_index(index),m_model((QAbstractTableModel*) index.model())
{
    setContentsMargins(0,0,0,0);
    connect(m_model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(dataChanged(QModelIndex,QModelIndex)));
}

DelegateWidgetBase::~DelegateWidgetBase()
{
    
}

void DelegateWidgetBase::dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    if (topLeft.row() <= m_index.row() && bottomRight.row() >= m_index.row()) {
        indexChanged();
        qDebug() << "DATA CHANGED";
    }
}