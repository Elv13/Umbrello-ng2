#ifndef DOCK_CLASS_TEMPLATE_H
#define DOCK_CLASS_TEMPLATE_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class ClassTemplatesModel;

class ClassTemplates : public PageBase
{
   Q_OBJECT
   public:
       ClassTemplates(QWidget* parent = NULL);
       virtual ~ClassTemplates();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        ClassTemplatesModel* m_pModel;

};

#endif
