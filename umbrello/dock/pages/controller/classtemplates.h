#ifndef DOCK_CLASS_TEMPLATE_H
#define DOCK_CLASS_TEMPLATE_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class ClassTemplates : public QWidget
{
   Q_OBJECT
   public:
       ClassTemplates(QWidget* parent = NULL);
       virtual ~ClassTemplates();

    private:
        Ui_GenericTable* ui;

};

#endif
