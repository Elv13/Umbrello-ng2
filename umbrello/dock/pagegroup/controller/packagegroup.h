#ifndef DOCK_PACKAGE_GROUP_H
#define DOCK_PACKAGE_GROUP_H

#include "ui_package.h"

#include <QtGui/QWidget>

class PackageGroup : public QWidget
{
   Q_OBJECT
   public:
       PackageGroup(QWidget* parent = NULL);
       virtual ~PackageGroup();

    private:
        Ui_PackageTabGroup* ui;

};

#endif
