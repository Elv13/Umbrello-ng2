#ifndef DOCK_PACKAGE_GENERAL_H
#define DOCK_PACKAGE_GENERAL_H

#include "ui_packageGeneral.h"

#include <QtGui/QWidget>

class PackageGeneral : public QWidget
{
   Q_OBJECT
   public:
       PackageGeneral(QWidget* parent = NULL);
       virtual ~PackageGeneral();

    private:
        Ui_PackageGeneral* ui;

};

#endif
