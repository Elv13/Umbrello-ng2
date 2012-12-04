#ifndef DOCK_VISIBILITY_SELECTOR_BASE_H
#define DOCK_VISIBILITY_SELECTOR_BASE_H

#include <QtGui/QWidget>

#include <QtCore/QAbstractTableModel>
#include "delegatewidgetbase.h"

class KComboBox;

class VisibilitySelector : public DelegateWidgetBase
{
   Q_OBJECT
   public:
       VisibilitySelector(const QModelIndex& index, QWidget* parent = NULL);
       virtual ~VisibilitySelector();

    protected:
        virtual void indexChanged();

    private:
        KComboBox* m_combo;

};

#endif
