#ifndef DOCK_ENUM_LITERALS_H
#define DOCK_ENUM_LITERALS_H

#include "ui_genericTable.h"

#include "pagebase.h"
class QWidget;
class EnumLiteralsModel;

class EnumLiterals : public PageBase
{
   Q_OBJECT
   public:
       EnumLiterals(QWidget* parent = NULL);
       virtual ~EnumLiterals();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_GenericTable* ui;
        EnumLiteralsModel* m_pModel;

};

#endif
