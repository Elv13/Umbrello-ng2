#ifndef DOCK_CLASS_ATTRIBUTES_H
#define DOCK_CLASS_ATTRIBUTES_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class ClassAttributesModel;

class ClassAttributes : public PageBase
{
   Q_OBJECT
   public:
       ClassAttributes(QWidget* parent = NULL);
       virtual ~ClassAttributes();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        ClassAttributesModel* m_pModel;
        
    private slots:
        void rowsInserted();

};

#endif
