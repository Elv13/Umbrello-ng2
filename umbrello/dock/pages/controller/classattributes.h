#ifndef DOCK_CLASS_ATTRIBUTES_H
#define DOCK_CLASS_ATTRIBUTES_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class ClassAttributes : public QWidget
{
   Q_OBJECT
   public:
       ClassAttributes(QWidget* parent = NULL);
       virtual ~ClassAttributes();

    private:
        Ui_GenericTable* ui;

};

#endif
