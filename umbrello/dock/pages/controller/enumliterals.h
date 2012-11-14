#ifndef DOCK_ENUM_LITERALS_H
#define DOCK_ENUM_LITERALS_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class EnumLiterals : public QWidget
{
   Q_OBJECT
   public:
       EnumLiterals(QWidget* parent = NULL);
       virtual ~EnumLiterals();

    private:
        Ui_GenericTable* ui;

};

#endif
