#ifndef DOCK_CLASS_OPERATIONS_H
#define DOCK_CLASS_OPERATIONS_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class ClassOperations : public QWidget
{
   Q_OBJECT
   public:
       ClassOperations(QWidget* parent = NULL);
       virtual ~ClassOperations();

    private:
        Ui_GenericTable* ui;

};

#endif
