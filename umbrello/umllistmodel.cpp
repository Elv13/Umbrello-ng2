#include "umllistmodel.h"

#include <QtCore/QDebug>
#include <KLocale>

#include "debug_utils.h"
#include "umldoc.h"
#include "idchangelog.h"
#include "model_utils.h"
#include "package.h"
#include "folder.h"
#include "uniqueid.h"
#include "classifier.h"
#include "operation.h"
#include "uml.h"
#include "umlview.h"
#include "docwindow.h"
#include "enum.h"
#include "entity.h"

UMLListModel::UMLListModel()
    : m_rv(0),
    m_datatypeFolder(0),
    m_bCreatingChildObject(false),
    m_doc(UMLApp::app()->document())
{
    
}

UMLListModel::~UMLListModel()
{
    delete m_datatypeFolder;
}

/**
 *
 */
bool UMLListModel::loadFromXMI(QDomElement & element)
{
    QDomNode node = element.firstChild();
    QDomElement domElement = node.toElement();
    m_doc->writeToStatusBar(i18n("Loading listview..."));
    while (!domElement.isNull()) {
        qDebug() << "\n\n\nHERE" << domElement.tagName();
        if (domElement.tagName() == "listitem") {
            QString type = domElement.attribute("type", "-1");
            if (type == "-1")
                return false;
            UMLListViewItem::ListViewType lvType = (UMLListViewItem::ListViewType)type.toInt();
            if (lvType == UMLListViewItem::lvt_View) {
                if (!loadChildrenFromXMI(m_rv, domElement))
                    return false;
            } else
                return false;
        }
        node = node.nextSibling();
        domElement = node.toElement();

    }//end while
    return true;
}

/**
 *
 */
bool UMLListModel::loadChildrenFromXMI(UMLListViewItem * parent, QDomElement & element)
{
    QDomNode node = element.firstChild();
    QDomElement domElement = node.toElement();
//     qDebug() << "HERE2" << domElement.tagName();
    while (!domElement.isNull()) {
        node = domElement.nextSibling();
        if (domElement.tagName() != "listitem") {
            domElement = node.toElement();
            continue;
        }
        QString id = domElement.attribute("id", "-1");
        QString type = domElement.attribute("type", "-1");
        QString label = domElement.attribute("label", "");
        QString open = domElement.attribute("open", "1");
        if (type == "-1")
            return false;
        UMLListViewItem::ListViewType lvType = (UMLListViewItem::ListViewType)type.toInt();
        bool bOpen = (bool)open.toInt();
        Uml::IDType nID = STR2ID(id);
        UMLObject * pObject = 0;
        UMLListViewItem * item = 0;
        if (nID != Uml::id_None) {
            // The following is an ad hoc hack for the copy/paste code.
            // The clip still contains the old children although new
            // UMLCLassifierListItems have already been created.
            // If the IDChangeLog finds new IDs this means we are in
            // copy/paste and need to adjust the child listitems to the
            // new UMLCLassifierListItems.
            IDChangeLog *idchanges = m_doc->changeLog();
            if (idchanges) {
                Uml::IDType newID = idchanges->findNewID(nID);
                if (newID != Uml::id_None) {
//                     DEBUG(DBG_SRC) << " using id " << ID2STR(newID)
//                                    << " instead of " << ID2STR(nID);
                    nID = newID;
                }
            }
            /************ End of hack for copy/paste code ************/

            pObject = m_doc->findObjectById(nID);
            if (pObject) {
                if (label.isEmpty())
                    label = pObject->name();
            } else if (Model_Utils::typeIsFolder(lvType)) {
                // Synthesize the UMLFolder here
                UMLObject *umlParent = parent->umlObject();
                UMLPackage *parentPkg = dynamic_cast<UMLPackage*>(umlParent);
                if (parentPkg == 0) {
                    uError() << "umlParent(" << umlParent << ") is not a UMLPackage";
                    domElement = node.toElement();
                    continue;
                }
                UMLFolder *f = new UMLFolder(label, nID);
                f->setUMLPackage(parentPkg);
                parentPkg->addObject(f);
                pObject = f;
                item = new UMLListViewItem(parent, label, lvType, pObject);
                // Moving all relevant UMLObjects to the new UMLFolder is done below,
                // in the switch(lvType)
            }
        } else if (Model_Utils::typeIsRootView(lvType)) {
            // Predefined folders did not have their ID set.
            const Uml::ModelType mt = Model_Utils::convert_LVT_MT(lvType);
            nID = m_doc->rootFolder(mt)->id();
        } else if (Model_Utils::typeIsFolder(lvType)) {
            // Pre-1.2 format: Folders did not have their ID set.
            // Pull a new ID now.
            nID = UniqueID::get();
        } else {
            uError() << "item of type " << type << " has no ID, skipping.";
            domElement = node.toElement();
            continue;
        }

        switch (lvType) {
        case UMLListViewItem::lvt_Actor:
        case UMLListViewItem::lvt_UseCase:
        case UMLListViewItem::lvt_Class:
        case UMLListViewItem::lvt_Interface:
        case UMLListViewItem::lvt_Datatype:
        case UMLListViewItem::lvt_Enum:
        case UMLListViewItem::lvt_Entity:
        case UMLListViewItem::lvt_Package:
        case UMLListViewItem::lvt_Subsystem:
        case UMLListViewItem::lvt_Component:
        case UMLListViewItem::lvt_Node:
        case UMLListViewItem::lvt_Artifact:
        case UMLListViewItem::lvt_Logical_Folder:
        case UMLListViewItem::lvt_UseCase_Folder:
        case UMLListViewItem::lvt_Component_Folder:
        case UMLListViewItem::lvt_Deployment_Folder:
        case UMLListViewItem::lvt_EntityRelationship_Folder:
        case UMLListViewItem::lvt_Category:
            item = findItem(nID);
            if (item == 0) {
                uError() << "INTERNAL ERROR: "
                    << "findItem(id " << ID2STR(nID) << ") returns 0";
                /*
                if (pObject && pObject->getUMLPackage() &&
                        parent->type() != UMLListViewItem::lvt_Package) {
                    // Pre-1.2 file format:
                    // Objects were not nested in their packages.
                    // Synthesize the nesting here.
                    UMLPackage *umlpkg = pObject->getUMLPackage();
                    UMLListViewItem *pkgItem = findUMLObject(umlpkg);
                    if (pkgItem == 0) {
                        DEBUG(DBG_SRC) << "synthesizing ListViewItem for package "
                                       << ID2STR(umlpkg->ID());
                        pkgItem = new UMLListViewItem(parent, umlpkg->getName(),
                                                      UMLListViewItem::lvt_Package, umlpkg);
                        pkgItem->setOpen(true);
                    }
                    item = new UMLListViewItem(pkgItem, label, lvType, pObject);
                } else {
                    item = new UMLListViewItem(parent, label, lvType, pObject);
                }
                 */
            } else if (parent != item->parent()) {
                // The existing item was created by the slot event triggered
                // by the loading of the corresponding model object from the
                // XMI file.
                // This early creation is done in order to support the loading
                // of foreign XMI files that do not have the umbrello specific
                // <listview> tag.
                // However, now that we encountered the real <listview> info,
                // we need to delete the existing item: Its parent is always
                // one of the default predefined folders, but the actual
                // listview item might be located in a user created folder.
                // Thanks to Achim Spangler for spotting the problem.
                UMLListViewItem *itmParent = dynamic_cast<UMLListViewItem*>(item->parent());
//                 DEBUG(DBG_SRC) << item->text(0) << " parent "
//                                << parent->text(0) << " (" << parent << ") != "
//                                << itmParent->text(0) << " (" << itmParent << ")";
                if (item == m_datatypeFolder && itmParent == m_lv[Uml::ModelType::Logical]) {
//                     DEBUG(DBG_SRC) << "Reparenting the Datatypes folder is prohibited";
                } else {
                    UMLListViewItem *newItem = moveObject(nID, lvType, parent);
                    item = newItem;
                    if (item) {
//                         DEBUG(DBG_SRC) << "Attempted reparenting of " << item->text(0)
//                                        << "(current parent: " << (itmParent ? itmParent->text(0) : "0")
//                                        << ", new parent: " << parent->text(0) << ")";
                    }
                }
            }
            break;
        case UMLListViewItem::lvt_Attribute:
        case UMLListViewItem::lvt_EntityAttribute:
        case UMLListViewItem::lvt_Template:
        case UMLListViewItem::lvt_Operation:
        case UMLListViewItem::lvt_EnumLiteral:
        case UMLListViewItem::lvt_UniqueConstraint:
        case UMLListViewItem::lvt_PrimaryKeyConstraint:
        case UMLListViewItem::lvt_ForeignKeyConstraint:
        case UMLListViewItem::lvt_CheckConstraint:
            item = findItem(nID);
            if (item == 0) {
//                 DEBUG(DBG_SRC) << "item " << ID2STR(nID) << " (of type "
//                                << UMLListViewItem::toString(lvType) << ") does not yet exist...";
                UMLObject* umlObject = parent->umlObject();
                if (!umlObject) {
//                     DEBUG(DBG_SRC) << "And also the parent->umlObject() does not exist";
                    return false;
                }
                if (nID == Uml::id_None) {
                    uWarning() << "lvtype " << UMLListViewItem::toString(lvType) << " has id -1";
                } else {
                    UMLClassifier *classifier = dynamic_cast<UMLClassifier*>(umlObject);
                    if (classifier) {
                        umlObject = classifier->findChildObjectById(nID);
                        if (umlObject) {
                            connectNewObjectsSlots(umlObject);
                            label = umlObject->name();
                            item = new UMLListViewItem(parent, label, lvType, umlObject);
                        } else {
//                             DEBUG(DBG_SRC) << "lvtype " << UMLListViewItem::toString(lvType)
//                                            << " child object " << ID2STR(nID) << " not found";
                        }
                    } else {
//                         DEBUG(DBG_SRC) << "cast to classifier object failed";
                    }
                }
            }
            break;
        case UMLListViewItem::lvt_Logical_View:
            item = m_lv[Uml::ModelType::Logical];
            break;
        case UMLListViewItem::lvt_Datatype_Folder:
            item = m_datatypeFolder;
            break;
        case UMLListViewItem::lvt_UseCase_View:
            item = m_lv[Uml::ModelType::UseCase];
            break;
        case UMLListViewItem::lvt_Component_View:
            item = m_lv[Uml::ModelType::Component];
            break;
        case UMLListViewItem::lvt_Deployment_View:
            item = m_lv[Uml::ModelType::Deployment];
            break;
        case UMLListViewItem::lvt_EntityRelationship_Model:
            item = m_lv[Uml::ModelType::EntityRelationship];
            break;
        default:
            if (Model_Utils::typeIsDiagram(lvType)) {
                item = new UMLListViewItem(parent, label, lvType, nID);
                qDebug() << "ICI" << lvType << id << m_diagramsById.size() <<  "end";
                if (!m_diagramsById[id]) {
                    UmlElementNode* e = new UmlElementNode;
                    e->isTopLevel = true;
                    e->row = m_diagrams.size();
                    e->item = item;
                    e->model = 0;
                    m_diagramsById[id] = e;
                    m_diagrams << e;
                }
                else {
                    qDebug() << "ADDING TO EXISTING";
                    m_diagramsById[id]->item = item;
                    m_diagramsById[id]->row = m_diagrams.size();
                    m_diagrams << m_diagramsById[id];
                }
                emit sigDiagramListChanged();
            } else {
                uError() << "INTERNAL ERROR: unexpected listview type "
                    << UMLListViewItem::toString(lvType) << " (ID " << ID2STR(nID) << ")";
            }
            break;
        }//end switch

        if (item)  {
            item->setOpen((bool)bOpen);
            if (!loadChildrenFromXMI(item, domElement)) {
                return false;
            }
        } else {
            uWarning() << "unused list view item " << ID2STR(nID)
                       << " of lvtype " << UMLListViewItem::toString(lvType);
        }
        domElement = node.toElement();
    }//end while
    return true;
}

/**
 * Searches through the tree for the item with the given ID.
 *
 * @param id   The ID to search for.
 * @return     The item with the given ID or 0 if not found.
 */
UMLListViewItem* UMLListModel::findItem(Uml::IDType id)
{
    UMLListViewItem *topLevel = static_cast<UMLListViewItem*>(topLevelItem(0));
    UMLListViewItem *item = topLevel->findItem(id);
    if (item)
        return item;
    return 0;
}


/**
 * Moves an object given is unique ID and listview type to an
 * other listview parent item.
 * Also takes care of the corresponding move in the model.
 */
UMLListViewItem * UMLListModel::moveObject(Uml::IDType srcId, UMLListViewItem::ListViewType srcType,
        UMLListViewItem *newParent)
{
    if (newParent == 0)
        return 0;
    UMLListViewItem * move = findItem(srcId);
    if (move == 0)
        return 0;

    UMLObject *newParentObj = 0;
    // Remove the source object at the old parent package.
    UMLObject *srcObj = m_doc->findObjectById(srcId);
    if (srcObj) {
        newParentObj = newParent->umlObject();
        if (srcObj == newParentObj) {
            uError() << srcObj->name() << ": Cannot move onto self";
            return 0;
        }
        UMLPackage *srcPkg = srcObj->umlPackage();
        if (srcPkg) {
            if (srcPkg == newParentObj) {
                uError() << srcObj->name() << ": Object is already in target package";
                return 0;
            }
            srcPkg->removeObject(srcObj);
        }
    }

    UMLListViewItem::ListViewType newParentType = newParent->type();
//     DEBUG(DBG_SRC) << "newParentType is " << newParentType;
    UMLListViewItem *newItem = 0;

    //make sure trying to place in correct location
    switch (srcType) {
    case UMLListViewItem::lvt_UseCase_Folder:
    case UMLListViewItem::lvt_Actor:
    case UMLListViewItem::lvt_UseCase:
    case UMLListViewItem::lvt_UseCase_Diagram:
        if (newParentType == UMLListViewItem::lvt_UseCase_Folder ||
                newParentType == UMLListViewItem::lvt_UseCase_View) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_Component_Folder:
    case UMLListViewItem::lvt_Artifact:
    case UMLListViewItem::lvt_Component_Diagram:
        if (newParentType == UMLListViewItem::lvt_Component_Folder ||
                newParentType == UMLListViewItem::lvt_Component_View) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_Subsystem:
        if (newParentType == UMLListViewItem::lvt_Component_Folder ||
                newParentType == UMLListViewItem::lvt_Component_View ||
                newParentType == UMLListViewItem::lvt_Subsystem) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_Component:
        if (newParentType == UMLListViewItem::lvt_Component_Folder ||
                newParentType == UMLListViewItem::lvt_Component_View ||
                newParentType == UMLListViewItem::lvt_Component ||
                newParentType == UMLListViewItem::lvt_Subsystem) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_Deployment_Folder:
    case UMLListViewItem::lvt_Node:
    case UMLListViewItem::lvt_Deployment_Diagram:
        if (newParentType == UMLListViewItem::lvt_Deployment_Folder ||
                newParentType == UMLListViewItem::lvt_Deployment_View) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_EntityRelationship_Folder:
    case UMLListViewItem::lvt_Entity:
    case UMLListViewItem::lvt_Category:
    case UMLListViewItem::lvt_EntityRelationship_Diagram:
        if (newParentType == UMLListViewItem::lvt_EntityRelationship_Folder ||
                newParentType == UMLListViewItem::lvt_EntityRelationship_Model) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_Collaboration_Diagram:
    case UMLListViewItem::lvt_Class_Diagram:
    case UMLListViewItem::lvt_State_Diagram:
    case UMLListViewItem::lvt_Activity_Diagram:
    case UMLListViewItem::lvt_Sequence_Diagram:
    case UMLListViewItem::lvt_Logical_Folder:
        if (newParentType == UMLListViewItem::lvt_Logical_Folder ||
                newParentType == UMLListViewItem::lvt_Logical_View) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            addAtContainer(newItem, newParent);
        }
        break;
    case UMLListViewItem::lvt_Class:
    case UMLListViewItem::lvt_Package:
    case UMLListViewItem::lvt_Interface:
    case UMLListViewItem::lvt_Enum:
    case UMLListViewItem::lvt_Datatype:
        if (newParentType == UMLListViewItem::lvt_Logical_Folder ||
                newParentType == UMLListViewItem::lvt_Datatype_Folder ||
                newParentType == UMLListViewItem::lvt_Logical_View ||
                newParentType == UMLListViewItem::lvt_Class ||
                newParentType == UMLListViewItem::lvt_Interface ||
                newParentType == UMLListViewItem::lvt_Package) {
            newItem = move->deepCopy(newParent);
            if (m_doc->loading())         // deletion is not safe while loading
                move->setVisible(false);  // (the <listview> XMI may be corrupted)
            else
                delete move;
            UMLCanvasObject *o = static_cast<UMLCanvasObject*>(newItem->umlObject());
            if (o == 0) {
//                 DEBUG(DBG_SRC) << "moveObject: newItem's UMLObject is 0";
            } else if (newParentObj == 0) {
                uError() << o->name() << ": newParentObj is 0";
            } else {
                UMLPackage *pkg = static_cast<UMLPackage*>(newParentObj);
                o->setUMLPackage(pkg);
                pkg->addObject(o);
            }
            UMLView *currentView = UMLApp::app()->currentView();
            if (currentView)
                currentView->umlScene()->updateContainment(o);
        }
        break;
    case UMLListViewItem::lvt_Attribute:
    case UMLListViewItem::lvt_Operation:
        if (newParentType == UMLListViewItem::lvt_Class ||
                newParentType == UMLListViewItem::lvt_Interface) {
            // update list view

            newItem = move->deepCopy(newParent);
            // we don't delete move right away, it will be deleted in slots,
            // called by subsequent steps
            //delete move;

            // update model objects
            m_bCreatingChildObject = true;

            UMLClassifier *oldParentClassifier = dynamic_cast<UMLClassifier*>(srcObj->parent());
            UMLClassifier *newParentClassifier = dynamic_cast<UMLClassifier*>(newParentObj);
            if (srcType == UMLListViewItem::lvt_Attribute) {
                UMLAttribute *att = dynamic_cast<UMLAttribute*>(srcObj);
                // We can't use the existing 'att' directly
                // because its parent is fixed to the old classifier
                // and we have no way of changing that:
                // QObject does not permit changing the parent().
                if (att == 0) {
                    uError() << "moveObject internal error: srcObj "
                        << srcObj->name() << " is not a UMLAttribute";
                } else if (oldParentClassifier->takeItem(att) == -1) {
                    uError() << "moveObject: oldParentClassifier->takeItem(att "
                        << att->name() << ") returns 0";
                } else {
                    const QString& nm = att->name();
                    UMLAttribute *newAtt = newParentClassifier->createAttribute(nm,
                                           att->getType(),
                                           att->visibility(),
                                           att->getInitialValue());
                    newItem->setUMLObject(newAtt);
                    newParent->addClassifierListItem(newAtt, newItem);

                    connectNewObjectsSlots(newAtt);
                    // Let's not forget to update the DocWindow::m_pObject
                    // because the old one is about to be physically deleted !
                    UMLApp::app()->docWindow()->showDocumentation(newAtt, true);
                    delete att;
                }
            } else {
                UMLOperation *op = dynamic_cast<UMLOperation*>(srcObj);
                // We can't use the existing 'op' directly
                // because its parent is fixed to the old classifier
                // and we have no way of changing that:
                // QObject does not permit changing the parent().
                if (op && oldParentClassifier->takeItem(op) != -1) {
                    bool isExistingOp;
                    Model_Utils::NameAndType_List ntDummyList;
                    // We need to provide a dummy NameAndType_List
                    // else UMLClassifier::createOperation will
                    // bring up an operation dialog.
                    UMLOperation *newOp = newParentClassifier->createOperation(
                                              op->name(), &isExistingOp, &ntDummyList);
                    newOp->setType(op->getType());
                    newOp->setVisibility(op->visibility());
                    UMLAttributeList parmList = op->getParmList();
                    foreach(UMLAttribute* parm, parmList) {
                        UMLAttribute *newParm = new UMLAttribute(newParentClassifier,
                                parm->name(),
                                Uml::id_None,
                                parm->visibility(),
                                parm->getType(),
                                parm->getInitialValue());
                        newParm->setParmKind(parm->getParmKind());
                        newOp->addParm(newParm);
                    }
                    newItem->setUMLObject(newOp);
                    newParent->addClassifierListItem(newOp, newItem);

                    connectNewObjectsSlots(newOp);

                    // Let's not forget to update the DocWindow::m_pObject
                    // because the old one is about to be physically deleted !
                    UMLApp::app()->docWindow()->showDocumentation(newOp, true);
                    delete op;
                } else {
                    uError() << "moveObject: oldParentClassifier->takeItem(op) returns 0";
                }
            }
            m_bCreatingChildObject = false;
        }
        break;
    default:
        break;
    }
    return newItem;
}


/**
 * Auxiliary method for moveObject(): Adds the model object at the proper
 * new container (package if nested, UMLDoc if at global level), and
 * updates the containment relationships in the model.
 */
void UMLListModel::addAtContainer(UMLListViewItem *item, UMLListViewItem *parent)
{
    UMLCanvasObject *o = static_cast<UMLCanvasObject*>(item->umlObject());
    if (o == 0) {
//         DEBUG(DBG_SRC) << item->text(0) << ": item's UMLObject is 0";
    } else if (Model_Utils::typeIsContainer(parent->type())) {
        /**** TBC: Do this here?
                   If yes then remove that logic at the callers
                   and rename this method to moveAtContainer()
        UMLPackage *oldPkg = o->getUMLPackage();
        if (oldPkg)
            oldPkg->removeObject(o);
         *********/
        UMLPackage *pkg = static_cast<UMLPackage*>(parent->umlObject());
        o->setUMLPackage(pkg);
        pkg->addObject(o);
    } else {
        uError() << item->text(0) << ": parent type is " << parent->type();
    }
    UMLView *currentView = UMLApp::app()->currentView();
    if (currentView)
        currentView->umlScene()->updateContainment(o);
}


/**
 * Connect some signals into slots in the list view for newly created UMLObjects.
 */
void UMLListModel::connectNewObjectsSlots(UMLObject* object)
{
    UMLObject::ObjectType type = object->baseType();
    switch (type) {
    case UMLObject::ot_Class:
    case UMLObject::ot_Interface: {
        UMLClassifier *c = static_cast<UMLClassifier*>(object);
        connect(c, SIGNAL(attributeAdded(UMLClassifierListItem*)),
                this, SLOT(childObjectAdded(UMLClassifierListItem*)));
        connect(c, SIGNAL(attributeRemoved(UMLClassifierListItem*)),
                this, SLOT(childObjectRemoved(UMLClassifierListItem*)));
        connect(c, SIGNAL(operationAdded(UMLClassifierListItem*)),
                this, SLOT(childObjectAdded(UMLClassifierListItem*)));
        connect(c, SIGNAL(operationRemoved(UMLClassifierListItem*)),
                this, SLOT(childObjectRemoved(UMLClassifierListItem*)));
        connect(c, SIGNAL(templateAdded(UMLClassifierListItem*)),
                this, SLOT(childObjectAdded(UMLClassifierListItem*)));
        connect(c, SIGNAL(templateRemoved(UMLClassifierListItem*)),
                this, SLOT(childObjectRemoved(UMLClassifierListItem*)));
        connect(object, SIGNAL(modified()), this, SLOT(slotObjectChanged()));
    }
    break;
    case UMLObject::ot_Enum: {
        UMLEnum *e = static_cast<UMLEnum*>(object);
        connect(e, SIGNAL(enumLiteralAdded(UMLClassifierListItem*)),
                this, SLOT(childObjectAdded(UMLClassifierListItem*)));
        connect(e, SIGNAL(enumLiteralRemoved(UMLClassifierListItem*)),
                this, SLOT(childObjectRemoved(UMLClassifierListItem*)));
    }
    connect(object, SIGNAL(modified()), this, SLOT(slotObjectChanged()));
    break;
    case UMLObject::ot_Entity: {
        UMLEntity *ent = static_cast<UMLEntity*>(object);
        connect(ent, SIGNAL(entityAttributeAdded(UMLClassifierListItem*)),
                this, SLOT(childObjectAdded(UMLClassifierListItem*)));
        connect(ent, SIGNAL(entityAttributeRemoved(UMLClassifierListItem*)),
                this, SLOT(childObjectRemoved(UMLClassifierListItem*)));
        connect(ent, SIGNAL(entityConstraintAdded(UMLClassifierListItem*)),
                this, SLOT(childObjectAdded(UMLClassifierListItem*)));
        connect(ent, SIGNAL(entityConstraintRemoved(UMLClassifierListItem*)),
                this, SLOT(childObjectRemoved(UMLClassifierListItem*)));
    }
    connect(object, SIGNAL(modified()), this, SLOT(slotObjectChanged()));
    break;
    case UMLObject::ot_Datatype:
    case UMLObject::ot_Attribute:
    case UMLObject::ot_Operation:
    case UMLObject::ot_Template:
    case UMLObject::ot_EnumLiteral:
    case UMLObject::ot_EntityAttribute:
    case UMLObject::ot_UniqueConstraint:
    case UMLObject::ot_ForeignKeyConstraint:
    case UMLObject::ot_CheckConstraint:
    case UMLObject::ot_Package:
    case UMLObject::ot_Actor:
    case UMLObject::ot_UseCase:
    case UMLObject::ot_Component:
    case UMLObject::ot_Artifact:
    case UMLObject::ot_Node:
    case UMLObject::ot_Folder:
    case UMLObject::ot_Category:
        connect(object, SIGNAL(modified()), this, SLOT(slotObjectChanged()));
        break;
    case UMLObject::ot_UMLObject:
    case UMLObject::ot_Association:
    case UMLObject::ot_Stereotype:
        break;
    default:
        uWarning() << "unknown type in connectNewObjectsSlots";
        break;
    }
}

/**
 * Adds a new operation, attribute or template item to a classifier.
 * @param obj the child object
 */
void UMLListModel::childObjectAdded(UMLClassifierListItem* obj)
{
    UMLClassifier *parent = const_cast<UMLClassifier*>(dynamic_cast<const UMLClassifier*>(sender()));
    childObjectAdded(obj, parent);
}



/**
 * Deletes the list view item.
 * @param obj the object to remove
 */
void UMLListModel::childObjectRemoved(UMLClassifierListItem* obj)
{
    UMLClassifier *parent = const_cast<UMLClassifier*>(dynamic_cast<const UMLClassifier*>(sender()));
    UMLListViewItem *parentItem = findUMLObject(parent);
    if (parentItem == 0) {
        uError() << obj->name() << ": cannot find parent UMLListViewItem";
        return;
    }
    parentItem->deleteChildItem(obj);
}



/**
 * Find an UMLObject in the listview.
 *
 * @param p   Pointer to the object to find in the list view.
 * @return    Pointer to the UMLObject found or NULL if not found.
 */
UMLListViewItem * UMLListModel::findUMLObject(const UMLObject *p) const
{
    for (int i=0; i < topLevelItemCount(); ++i) {
        UMLListViewItem *item = static_cast<UMLListViewItem*>(topLevelItem(i));
        UMLListViewItem *testItem = item->findUMLObject(p);
        if (testItem)
            return testItem;
    }
    return 0;
}


/**
 * Adds a new operation, attribute or template item to a classifier, identical to
 * childObjectAdded(obj) but with an explicit parent.
 * @param child the child object
 * @param parent the parent object
 */
void UMLListModel::childObjectAdded(UMLClassifierListItem* child, UMLClassifier* parent)
{
    if (m_bCreatingChildObject)
        return;
    const QString text = child->toString(Uml::SignatureType::SigNoVis);
    UMLListViewItem *childItem = 0;
    UMLListViewItem *parentItem = findUMLObject(parent);
    if (parentItem == 0) {
        DEBUG(DBG_SRC) << child->name() << ": parent " << parent->name()
                       << " does not yet exist, creating it now.";
        const UMLListViewItem::ListViewType lvt = Model_Utils::convert_OT_LVT(parent);
        parentItem = new UMLListViewItem(m_lv[Uml::ModelType::Logical], parent->name(), lvt, parent);
    } else {
        childItem = parentItem->findChildObject(child);
    }
    if (childItem) {
        childItem->setText(text);
    } else {
        const UMLListViewItem::ListViewType lvt = Model_Utils::convert_OT_LVT(child);
        childItem = new UMLListViewItem(parentItem, text, lvt, child);
        if (! m_doc->loading()) {
//             scrollToItem(childItem); //TODO add a signal
//             clearSelection(); //TODO add a signal
//             setSelected(childItem, true); //TODO add a signal
        }
        connectNewObjectsSlots(child);
    }
}

/**
 * Searches the tree for a diagram (view).
 * Warning: these method may return in some cases the wrong diagram
 * Used by findView().
 */
UMLListViewItem* UMLListModel::recursiveSearchForView(UMLListViewItem* listViewItem,
        UMLListViewItem::ListViewType type, Uml::IDType id)
{
    if (!listViewItem)
        return 0;

    if (Model_Utils::typeIsFolder(listViewItem->type())) {
        for (int i=0; i < listViewItem->childCount(); i++) {
            UMLListViewItem* child = listViewItem->childItem(i);
            UMLListViewItem* resultListViewItem = recursiveSearchForView(child, type, id);
            if (resultListViewItem)
                return resultListViewItem;
        }
    } else {
        if (listViewItem->type() == type && listViewItem->ID() == id)
            return listViewItem;
    }
    return 0;
}



/**
 * Searches through the tree for the item which represents the diagram given.
 * @param v  the diagram to search for
 * @return the item which represents the diagram
 */
UMLListViewItem* UMLListModel::findView(UMLView* v)
{
    if (!v) {
        uWarning() << "returning 0 - param is 0.";
        return 0;
    }
    UMLListViewItem* item;
    Uml::DiagramType dType = v->umlScene()->m_model->type();
    UMLListViewItem::ListViewType type = Model_Utils::convert_DT_LVT(dType);
    Uml::IDType id = v->umlScene()->m_model->ID();
    if (dType == Uml::DiagramType::UseCase) {
        item = m_lv[Uml::ModelType::UseCase];
    } else if (dType == Uml::DiagramType::Component) {
        item = m_lv[Uml::ModelType::Component];
    } else if (dType == Uml::DiagramType::Deployment) {
        item = m_lv[Uml::ModelType::Deployment];
    } else if (dType == Uml::DiagramType::EntityRelationship) {
        item = m_lv[Uml::ModelType::EntityRelationship];
    } else {
        item = m_lv[Uml::ModelType::Logical];
    }
    for (int i=0; i < item->childCount(); i++) {
        UMLListViewItem* foundItem = recursiveSearchForView(item->childItem(i), type, id);
        if (foundItem) {
            return foundItem;
        }
    }
    if (m_doc->loading()) {
        DEBUG(DBG_SRC) << "could not find " << v->umlScene()->name() << " in " << *item;
    } else {
        uWarning() << "could not find " << v->umlScene()->name() << " in " << *item;
    }
    return 0;
}



/**
 * This methods looks for a object in a folder an its subfolders recursive.
 * @param folder   The folder entry of the list view.
 * @param obj      The object to be found in the folder.
 * @return The object if found else a NULL pointer.
 */
UMLListViewItem * UMLListModel::findUMLObjectInFolder(UMLListViewItem* folder, UMLObject* obj)
{
    for (int i=0; i < folder->childCount(); ++i) {
        UMLListViewItem *item = folder->childItem(i);
        switch (item->type()) {
        case UMLListViewItem::lvt_Actor :
        case UMLListViewItem::lvt_UseCase :
        case UMLListViewItem::lvt_Class :
        case UMLListViewItem::lvt_Package :
        case UMLListViewItem::lvt_Subsystem :
        case UMLListViewItem::lvt_Component :
        case UMLListViewItem::lvt_Node :
        case UMLListViewItem::lvt_Artifact :
        case UMLListViewItem::lvt_Interface :
        case UMLListViewItem::lvt_Datatype :
        case UMLListViewItem::lvt_Enum :
        case UMLListViewItem::lvt_Entity :
        case UMLListViewItem::lvt_Category:
            if (item->umlObject() == obj)
                return item;
            break;
        case UMLListViewItem::lvt_Logical_Folder :
        case UMLListViewItem::lvt_UseCase_Folder :
        case UMLListViewItem::lvt_Component_Folder :
        case UMLListViewItem::lvt_Deployment_Folder :
        case UMLListViewItem::lvt_EntityRelationship_Folder :
        case UMLListViewItem::lvt_Datatype_Folder : {
            UMLListViewItem *temp = findUMLObjectInFolder(item, obj);
            if (temp)
                return temp;
        }
        default:
            break;
        }
    }
    return 0;
}

/**
 * Calls updateObject() on the item representing the sending object
 * no parameters, uses sender() to work out which object called the slot.
 */
void UMLListModel::slotObjectChanged()
{
    if (m_doc->loading()) { //needed for class wizard
        return;
    }
    UMLObject* obj = const_cast<UMLObject*>(dynamic_cast<const UMLObject*>(sender()));
    UMLListViewItem* item = findUMLObject(obj);
    if (item) {
        item->updateObject();
    }
}


//////////////////CUSTOM////////////////
UMLListViewItem * UMLListModel::topLevelItem(int i) const
{
    if (i > m_nodes.size())
        return NULL;
    else
        return m_nodes[i]->item;
}

int UMLListModel::topLevelItemCount() const
{
    return m_nodes.size();
}

void UMLListModel::addTopLevelItem(UMLListViewItem * item)
{
    UmlElementNode* e = new UmlElementNode;
    e->isTopLevel = true;
    e->item = item;
    e->row = m_diagrams.size();
    m_nodes << e;
}


void UMLListModel::addSceneModelForDiagrams(UMLSceneModel* sceneModel,QString id)
{
    qDebug() << "IN addSceneModelForDiagrams" << id << m_diagramsById[id] << "end";
    if (!m_diagramsById[id]) {
        UmlElementNode* e = new UmlElementNode;
        e->isTopLevel = true;
        e->item = 0;
        e->model = sceneModel;
        m_diagramsById[id]= e;
    }
}