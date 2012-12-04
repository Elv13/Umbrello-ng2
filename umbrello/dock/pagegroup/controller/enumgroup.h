#ifndef DOCK_ENUM_GROUP_H
#define DOCK_ENUM_GROUP_H

#include "ui_enum.h"

#include "pagegroupbase.h"

class EnumGroup : public PageGroupBase
{
   Q_OBJECT
   public:
       EnumGroup(QWidget* parent = NULL);
       virtual ~EnumGroup();

       virtual void setCurrentObject(UMLObject* o);

       virtual void focusName();

       //Getter
       virtual PageBase* currentPage();

    private:
        Ui_EnumTabGroup* ui;

};

#endif
