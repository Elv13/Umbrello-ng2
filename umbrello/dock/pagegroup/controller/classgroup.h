#ifndef DOCK_CLASS_GROUP_H
#define DOCK_CLASS_GROUP_H

#include "ui_class.h"

#include <QtGui/QWidget>

class ClassGroup : public QWidget
{
   Q_OBJECT
   public:
       ClassGroup(QWidget* parent = NULL);
       virtual ~ClassGroup();

    private:
        Ui_ClassTabGroup* ui;

};

#endif
