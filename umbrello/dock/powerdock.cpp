#include "powerdock.h"

#include <QtGui/QWidget>

#include "pagegroup.h"

#include "pagegroup/controller/classgroup.h"

PowerDock::PowerDock(QWidget* parent) : QDockWidget(parent)
{
    setObjectName("PowerDock");
    ClassGroup* gr = new ClassGroup(this);
    setWidget(gr);
}

PowerDock::~PowerDock()
{
    
}

void PowerDock::addPageGroup(PageGroup* group)
{
    
}