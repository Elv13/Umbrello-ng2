#ifndef DOCK_ENUM_GENERAL_H
#define DOCK_ENUM_GENERAL_H

#include "ui_enumGeneral.h"

#include <QtGui/QWidget>

class EnumGeneral : public QWidget
{
   Q_OBJECT
   public:
       EnumGeneral(QWidget* parent = NULL);
       virtual ~EnumGeneral();

    private:
        Ui_EnumGeneral* ui;

};

#endif
