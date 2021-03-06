#ifndef DOCK_PACKAGE_GENERAL_H
#define DOCK_PACKAGE_GENERAL_H

#include "ui_packageGeneral.h"

#include "pagebase.h"
class QWidget;
class DocTextEditor;

class PackageGeneral : public PageBase
{
   Q_OBJECT
   public:
       PackageGeneral(QWidget* parent = NULL);
       virtual ~PackageGeneral();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

        Ui_PackageGeneral* ui;
    private:
        DocTextEditor* m_pDoc;

};

#endif
