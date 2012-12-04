#ifndef DOCK_DELEGATE_WIDGET_BASE_H
#define DOCK_DELEGATE_WIDGET_BASE_H

#include <QtGui/QWidget>

#include <QtCore/QAbstractTableModel>

class ClassAssociationsModel;

class DelegateWidgetBase : public QWidget
{
   Q_OBJECT
   public:
       DelegateWidgetBase(const QModelIndex& index, QWidget* parent = NULL);
       virtual ~DelegateWidgetBase();

    protected:
        virtual void indexChanged() = 0;

        QModelIndex m_index;
        QAbstractTableModel* m_model;

    private slots:
        void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

};

#endif
