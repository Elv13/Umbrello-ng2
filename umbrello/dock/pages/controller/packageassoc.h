#ifndef DOCK_PACKAGE_ASSOC_H
#define DOCK_PACKAGE_ASSOC_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class PackageAssoc : public QWidget
{
   Q_OBJECT
   public:
       PackageAssoc(QWidget* parent = NULL);
       virtual ~PackageAssoc();

    private:
        Ui_GenericTable* ui;

};

#endif
