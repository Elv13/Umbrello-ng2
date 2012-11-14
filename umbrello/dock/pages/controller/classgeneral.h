#ifndef DOCK_CLASS_GENERAL_H
#define DOCK_CLASS_GENERAL_H

#include "ui_classGeneral.h"

#include <QtGui/QWidget>

class ClassGeneral : public QWidget
{
   Q_OBJECT
   public:
       ClassGeneral(QWidget* parent = NULL);
       virtual ~ClassGeneral();

    private:
        Ui_ClassGeneral* ui;

};

#endif
