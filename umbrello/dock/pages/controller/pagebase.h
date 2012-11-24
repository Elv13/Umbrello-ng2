#ifndef DOCK_PAGE_BASE_H
#define DOCK_PAGE_BASE_H

#include "ui_packageGeneral.h"

#include <QtGui/QWidget>
class UMLObject;

class PageBase : public QWidget
{
   Q_OBJECT
   public:
       PageBase(QWidget* parent = NULL);
       virtual ~PageBase();

       //Settings
       virtual void setCurrentObject(UMLObject* o) =0;
};

#endif
