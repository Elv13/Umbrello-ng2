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
    setCurrentObject(w->umlObject());
}

void PowerDock::setCurrentObject(UMLObject* w)
{
    if (m_pUmlObject == w) return;
    m_pUmlObject = w;
    setWindowTitle(m_pUmlObject->name());
    switch (w->baseType()) {
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
            break;
        case UMLObject::ot_Association:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Attribute:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Operation:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_EnumLiteral:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Template:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Component:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Artifact:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Node:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Stereotype:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Role:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Entity:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_EntityAttribute:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Folder:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_EntityConstraint:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_UniqueConstraint:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_ForeignKeyConstraint:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_CheckConstraint:
            m_pCurrentPageGroup =0;
            break;
        case UMLObject::ot_Category:
            m_pCurrentPageGroup =0;
            break;
    }
    if (m_pCurrentPageGroup)
        m_pCurrentPageGroup->setCurrentObject(w);
}

void PowerDock::focusName()
{
    if (m_pCurrentPageGroup) {
        m_pCurrentPageGroup->focusName();
    }
}