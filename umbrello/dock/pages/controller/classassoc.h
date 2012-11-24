#ifndef DOCK_CLASS_ASSOC_H
#define DOCK_CLASS_ASSOC_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class ClassAssociationsModel;

class ClassAssoc : public PageBase
{
   Q_OBJECT
   public:
       ClassAssoc(QWidget* parent = NULL);
       virtual ~ClassAssoc();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        ClassAssociationsModel* m_pModel;

};

#endif
