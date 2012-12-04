#ifndef DOCK_CLASS_GENERAL_H
#define DOCK_CLASS_GENERAL_H

#include "ui_classGeneral.h"

#include "pagebase.h"
class QWidget;

class ClassGeneral : public PageBase
{
   Q_OBJECT
   public:
       ClassGeneral(QWidget* parent = NULL);
       virtual ~ClassGeneral();

       //Setters
       virtual void setCurrentObject(UMLObject* o);

    private:
        Ui_ClassGeneral* ui;
        UMLObject* m_object;

    private slots:
        void slotNameChanged(QString name);
        void slotStereotypeChanged(QString stereotype);
        void slotAbstractChanged(bool abstract);
        void slotPackageChanged(QString package);
        void slotVisibilityChanged(int index);

};

#endif
