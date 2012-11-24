#ifndef DOCK_PACKAGE_GENERAL_H
#define DOCK_PACKAGE_GENERAL_H

#include "ui_packageGeneral.h"

#include "pagebase.h"
class QWidget;

class PackageGeneral : public PageBase
{
   Q_OBJECT
   public:
       PackageGeneral(QWidget* parent = NULL);
       virtual ~PackageGeneral();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_PackageGeneral* ui;

};

#endif
