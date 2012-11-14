#ifndef DOCK_PACKAGE_CONTENT_H
#define DOCK_PACKAGE_CONTENT_H

#include "ui_genericTable.h"

#include <QtGui/QWidget>

class PackageContent : public QWidget
{
   Q_OBJECT
   public:
       PackageContent(QWidget* parent = NULL);
       virtual ~PackageContent();

    private:
        Ui_GenericTable* ui;

};

#endif
