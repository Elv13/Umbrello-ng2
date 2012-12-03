#include "projectdock.h"
#include <QtGui/QWidget>
#include "projectdockmodel.h"
#include "umldoc.h"
#include <QtCore/QDebug>
#include "diagramlistdelegate.h"

ProjectDock::ProjectDock(QWidget* parent):QDockWidget(parent),ui(new Ui_ProjectDock())
{
    setObjectName("ProjectDock");
    setWindowTitle("Project");
    QWidget* center = new QWidget(this);
    ui->setupUi(center);
    
    DiagramListDelegate *delegate = new DiagramListDelegate(this);
    ui->m_pView->setItemDelegate(delegate);
    
    ProjectDockModel* model = new ProjectDockModel(this);
    ui->m_pView->setModel(model);
    setWidget(center);
    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),ui->m_pView,SLOT(expandAll()));
}

ProjectDock::~ProjectDock()
{
    
}

void ProjectDock::setDocument(UMLDoc *doc)
{
    if (m_doc && m_doc != doc) {
        //disconnect signals from old doc and reset view
    }
    m_doc = doc;

    connect(m_doc, SIGNAL(sigDiagramCreated(Uml::IDType)), this, SLOT(slotDiagramCreated(Uml::IDType)));
    connect(m_doc, SIGNAL(sigDiagramRemoved(Uml::IDType)), this, SLOT(slotDiagramRemoved(Uml::IDType)));
    connect(m_doc, SIGNAL(sigDiagramRenamed(Uml::IDType)), this, SLOT(slotDiagramRenamed(Uml::IDType)));
    connect(m_doc, SIGNAL(sigObjectCreated(UMLObject*)),   this, SLOT(slotObjectCreated(UMLObject*)));
    connect(m_doc, SIGNAL(sigObjectRemoved(UMLObject*)),   this, SLOT(slotObjectRemoved(UMLObject*)));
}

/**
 * Returns the document pointer. Called by the UMLListViewItem class.
 */
UMLDoc * ProjectDock::document() const
{
    return m_doc;
}

void ProjectDock::slotDiagramCreated(Uml::IDType t)
{
    qDebug() << "NEW DIAGRAM";
}

void ProjectDock::slotDiagramRemoved(Uml::IDType t)
{
    
}

void ProjectDock::slotDiagramRenamed(Uml::IDType t)
{
    
}

void ProjectDock::slotObjectCreated(UMLObject* o)
{
    if (o && o->baseType() == UMLObject::ot_Folder) {
        qDebug() << "NEW OBJECT" << o  << o->name();
    }
}

void ProjectDock::slotObjectRemoved(UMLObject* o)
{
    
}
