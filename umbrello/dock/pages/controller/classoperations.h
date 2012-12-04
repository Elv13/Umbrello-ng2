#ifndef DOCK_CLASS_OPERATIONS_H
#define DOCK_CLASS_OPERATIONS_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class ClassOperationsModel;

class ClassOperations : public PageBase
{
   Q_OBJECT
   public:
       ClassOperations(QWidget* parent = NULL);
       virtual ~ClassOperations();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        ClassOperationsModel* m_pModel;

    private slots:
        void rowsInserted();

};

#endif
