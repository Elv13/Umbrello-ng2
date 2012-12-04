#ifndef DOCK_DOC_DUCK_BUTTON_H // :)
#define DOCK_DOC_DUCK_BUTTON_H

#include "tintedbuttonbase.h"

class DocButton : public TintedButtonBase
{
   Q_OBJECT
   public:
       DocButton(const QModelIndex& index, QWidget* parent = NULL);
       virtual ~DocButton();

    protected:
        virtual void indexChanged();

};

#endif