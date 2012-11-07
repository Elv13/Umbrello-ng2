#ifndef POWERDOCK_H
#define POWERDOCK_H

#include <QtGui/QDockWidget>

class PageGroup;
class QWidget;

class PowerDock : public QDockWidget
{
    Q_OBJECT
public:
    PowerDock(QWidget* parent);
    virtual ~PowerDock();
    
    //Mutator
    void addPageGroup(PageGroup* group);
};

#endif