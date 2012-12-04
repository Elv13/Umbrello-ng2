#ifndef DOCK_SOURCE_BUTTON_H // :)
#define DOCK_SOURCE_BUTTON_H

#include "tintedbuttonbase.h"

class SourceButton : public TintedButtonBase
{
   Q_OBJECT
   public:
       SourceButton(const QModelIndex& index, QWidget* parent = NULL);
       virtual ~SourceButton();

    protected:
        virtual void indexChanged();

};

#endif