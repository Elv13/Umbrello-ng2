#ifndef DOCK_TINTED_BUTTON_BASE_H
#define DOCK_TINTED_BUTTON_BASE_H

#include <QtGui/QWidget>

#include <QtCore/QAbstractTableModel>
#include "delegatewidgetbase.h"

class QPushButton;

class ClassAssociationsModel;

class TintedButtonBase : public DelegateWidgetBase
{
   Q_OBJECT
   public:
       TintedButtonBase(const QModelIndex& index, QWidget* parent = NULL);
       virtual ~TintedButtonBase();
       void setText(const QString& text);

    protected:
        virtual void indexChanged() =0;

    private:
        QPushButton* m_button;

};

#endif
