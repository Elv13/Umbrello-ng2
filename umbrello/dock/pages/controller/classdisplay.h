#ifndef DOCK_CLASS_DISPLAY_H
#define DOCK_CLASS_DISPLAY_H

#include "ui_classDisplay.h"

#include <QtGui/QWidget>

class ClassDisplay : public QWidget
{
   Q_OBJECT
   public:
       ClassDisplay(QWidget* parent = NULL);
       virtual ~ClassDisplay();

    private:
        Ui_ClassDisplay* ui;
        enum Mode {
            Line,
            Background,
            Text,
        };

};

#endif
