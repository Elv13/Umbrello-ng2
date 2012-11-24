#ifndef DOCK_PACKAGE_CONTENT_H
#define DOCK_PACKAGE_CONTENT_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class PackageContentModel;

class PackageContent : public PageBase
{
   Q_OBJECT
   public:
       PackageContent(QWidget* parent = NULL);
       virtual ~PackageContent();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        PackageContentModel* m_pModel;

};

#endif
