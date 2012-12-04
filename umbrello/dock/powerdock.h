#ifndef POWERDOCK_H
#define POWERDOCK_H

#include <QtGui/QDockWidget>
#include <QtCore/QHash>

class PageGroup;
class QWidget;
class UMLWidget;
class PageGroupBase;
class UMLObject;

class PowerDock : public QDockWidget
{
    Q_OBJECT
public:
    PowerDock(QWidget* parent);
    virtual ~PowerDock();

    //Mutator
    void addPageGroup(PageGroup* group);

    //Setter
    void setCurrentWidget(UMLWidget* w);
    void setCurrentObject(UMLObject* w);

    //Mutator
    void focusName();
    void addRow();

private:
    //Enum
    enum PageGroupType {
        Class,
        Enum,
        Package,
    };
    //Attributes
//     UMLWidget* m_pUmlWidget;
    UMLObject* m_pUmlObject;
    QHash<PageGroupType,PageGroupBase*> m_hPages;
    PageGroupBase* m_pCurrentPageGroup;
};

#endif