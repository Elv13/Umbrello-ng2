#ifndef DOCK_CLASS_ASSOC_H
#define DOCK_CLASS_ASSOC_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class ClassAssoc : public QWidget
{
   Q_OBJECT
   public:
       ClassAssoc(QWidget* parent = NULL);
       virtual ~ClassAssoc();

    private:
        Ui_GenericTable* ui;

};

#endif
