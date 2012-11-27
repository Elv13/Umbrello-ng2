#ifndef PROJECTDOCK_H
#define PROJECTDOCK_H

#include <QtGui/QDockWidget>
#include <QtCore/QHash>
#include "ui_projectdock.h"

class PageGroup;
class QWidget;
class PageGroupBase;

class ProjectDock : public QDockWidget
{
    Q_OBJECT
public:
    ProjectDock(QWidget* parent = NULL);
    virtual ~ProjectDock();

private:
    //Attributes
    Ui_ProjectDock* ui;
};

#endif