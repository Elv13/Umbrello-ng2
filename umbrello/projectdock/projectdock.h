#ifndef PROJECTDOCK_H
#define PROJECTDOCK_H

#include <QtGui/QDockWidget>
#include <QtCore/QHash>
#include "ui_projectdock.h"
#include "uml.h"

class PageGroup;
class QWidget;
class PageGroupBase;
class UMLDoc;
class UMLObject;
class UMLListView;

class ProjectDock : public QDockWidget
{
    Q_OBJECT
public:
    ProjectDock(QWidget* parent = NULL);
    virtual ~ProjectDock();
    
    void setDocument(UMLDoc * doc);
    UMLDoc * document() const;
    
    //Setters
    void setCompleteView(UMLListView* view);

private:
    //Attributes
    Ui_ProjectDock* ui;
    UMLDoc*         m_doc;
    UMLListView*    m_pView;

private slots:
    void slotDiagramCreated(Uml::IDType t);
    void slotDiagramRemoved(Uml::IDType t);
    void slotDiagramRenamed(Uml::IDType t);
    void slotObjectCreated(UMLObject* o);
    void slotObjectRemoved(UMLObject* o);
};

#endif