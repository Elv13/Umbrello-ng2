#ifndef DOCK_PACKAGE_ASSOC_H
#define DOCK_PACKAGE_ASSOC_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class PackageAssociationsModel;

class PackageAssoc : public PageBase
{
   Q_OBJECT
   public:
       PackageAssoc(QWidget* parent = NULL);
       virtual ~PackageAssoc();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        PackageAssociationsModel* m_pModel;

};

#endif
