#ifndef DOCK_ENUM_GENERAL_H
#define DOCK_ENUM_GENERAL_H

#include "ui_enumGeneral.h"

#include "pagebase.h"
class QWidget;
class DocTextEditor;

class EnumGeneral : public PageBase
{
   Q_OBJECT
   public:
       EnumGeneral(QWidget* parent = NULL);
       virtual ~EnumGeneral();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_EnumGeneral* ui;
        DocTextEditor* m_pDoc;

};

#endif
