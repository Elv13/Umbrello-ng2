#ifndef DOCK_TYPE_SELECTOR_BASE_H
#define DOCK_TYPE_SELECTOR_BASE_H

#include <QtGui/QWidget>

#include <QtCore/QAbstractTableModel>
#include "delegatewidgetbase.h"

class QComboBox;

class TypeSelector : public DelegateWidgetBase
{
   Q_OBJECT
   public:
       TypeSelector(const QModelIndex& index, QWidget* parent = NULL);
       virtual ~TypeSelector();

    protected:
        virtual void indexChanged();

    private:
        QComboBox* m_combo;

};

#endif
