#include "powerdock.h"

#include <QtGui/QWidget>

#include "pagegroup.h"

#include "pagegroup/controller/pagegroupbase.h"
#include "pagegroup/controller/classgroup.h"
#include "pagegroup/controller/enumgroup.h"
#include "pagegroup/controller/packagegroup.h"

#include "umlwidget.h"
#include <QtCore/QDebug>

PowerDock::PowerDock(QWidget* parent) : QDockWidget(parent)
{
    setObjectName("PowerDock");
    ClassGroup* gr = new ClassGroup(this);
    m_hPages[PowerDock::Class] = gr;
    setWidget(gr);
    m_pCurrentPageGroup = gr;
}

PowerDock::~PowerDock()
{
    
}

void PowerDock::addPageGroup(PageGroup* group)
{
    
}

void PowerDock::setCurrentWidget(UMLWidget* w)
{
    if (m_pUmlWidget == w) return;
    m_pUmlWidget = w;
    setWindowTitle(m_pUmlWidget->name());
    switch (w->umlObject()->baseType()) {
        case UMLObject::ot_UMLObject:
            
            break;
        case UMLObject::ot_Actor:
            
            break;
        case UMLObject::ot_UseCase:
            
            break;
        case UMLObject::ot_Package:
            if (!m_hPages[PowerDock::Package]) {
                PackageGroup* gr = new PackageGroup(this);
                m_hPages[PowerDock::Package] = gr;
            }
            setWidget(m_hPages[PowerDock::Package]);
            m_pCurrentPageGroup = m_hPages[PowerDock::Package];
            qDebug() << "IS Paclage";
            break;
        case UMLObject::ot_Interface:
            
            break;
        case UMLObject::ot_Datatype:
            qDebug() << "IS DAATYPE";
            break;
        case UMLObject::ot_Enum:
            if (!m_hPages[PowerDock::Enum]) {
                EnumGroup* gr = new EnumGroup(this);
                m_hPages[PowerDock::Enum] = gr;
            }
            setWidget(m_hPages[PowerDock::Enum]);
            m_pCurrentPageGroup = m_hPages[PowerDock::Enum];
            qDebug() << "IS ENUM";
            break;
        case UMLObject::ot_Class:
            if (!m_hPages[PowerDock::Class]) {
                ClassGroup* gr = new ClassGroup(this);
                m_hPages[PowerDock::Class] = gr;
            }
            setWidget(m_hPages[PowerDock::Class]);
            m_pCurrentPageGroup = m_hPages[PowerDock::Class];
            qDebug() << "IS CLASS";
            break;
        case UMLObject::ot_Association:
            
            break;
        case UMLObject::ot_Attribute:
            
            break;
        case UMLObject::ot_Operation:
            
            break;
        case UMLObject::ot_EnumLiteral:
            
            break;
        case UMLObject::ot_Template:
            
            break;
        case UMLObject::ot_Component:
            
            break;
        case UMLObject::ot_Artifact:
            
            break;
        case UMLObject::ot_Node:
            
            break;
        case UMLObject::ot_Stereotype:
            
            break;
        case UMLObject::ot_Role:
            
            break;
        case UMLObject::ot_Entity:
            
            break;
        case UMLObject::ot_EntityAttribute:
            
            break;
        case UMLObject::ot_Folder:
            
            break;
        case UMLObject::ot_EntityConstraint:
            
            break;
        case UMLObject::ot_UniqueConstraint:
            
            break;
        case UMLObject::ot_ForeignKeyConstraint:
            
            break;
        case UMLObject::ot_CheckConstraint:
            
            break;
        case UMLObject::ot_Category:
            
            break;
    }
}