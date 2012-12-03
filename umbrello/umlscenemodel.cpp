#include "umlscenemodel.h"
#include "debug_utils.h"
#include "object_factory.h"
#include "objectnodewidget.h"
#include "objectwidget.h"
#include "activitywidget.h"
#include "actorwidget.h"
#include "artifactwidget.h"
#include "association.h"
#include "associationline.h"
#include "associationwidget.h"
#include "assocrules.h"
#include "attribute.h"
#include "boxwidget.h"
#include "classifier.h"
#include "classifierwidget.h"
#include "classoptionspage.h"
#include "cmds.h"
#include "componentwidget.h"
#include "datatypewidget.h"
#include "debug_utils.h"
#include "docwindow.h"
#include "entity.h"
#include "entitywidget.h"
#include "enumwidget.h"
#include "floatingtextwidget.h"
#include "folder.h"
#include "foreignkeyconstraint.h"
#include "forkjoinwidget.h"
#include "idchangelog.h"
#include "layoutgenerator.h"
#include "layoutgrid.h"
#include "listpopupmenu.h"
#include "messagewidget.h"
#include "model_utils.h"
#include "notewidget.h"
#include "object_factory.h"
#include "objectnodewidget.h"
#include "objectwidget.h"
#include "package.h"
#include "packagewidget.h"
#include "pinwidget.h"
#include "seqlinewidget.h"
#include "signalwidget.h"
#include "statewidget.h"
#include "toolbarstatefactory.h"
#include "uml.h"
#include "umldoc.h"
#include "umldragdata.h"
#include "umllistview.h"
#include "umllistviewitem.h"
#include "umlobject.h"
#include "umlobjectlist.h"
#include "umlrole.h"
#include "umlview.h"
#include "umlviewdialog.h"
#include "umlviewimageexporter.h"
#include "umlwidget.h"
#include "uniqueid.h"
#include "widget_factory.h"
#include "widget_utils.h"
#include "widgetlist_utils.h"
#include "umlscenemodel.h"

UMLSceneModel::UMLSceneModel():
    m_nLocalID(Uml::id_None),
    m_nID(Uml::id_None),
    m_Type(Uml::DiagramType::Undefined),
    m_Name(QString()),
    m_Documentation(QString()),
    m_isOpen(true),
    m_Options(Settings::optionState())
{
    
}

UMLSceneModel::~UMLSceneModel()
{
    
}

/**
 * Loads the "diagram" tag.
 */
bool UMLSceneModel::loadFromXMI(QDomElement & qElement)
{
    QString id = qElement.attribute("xmi.id", "-1");
    qDebug() << "QWERTY" << id;
    UMLApp::app()->listView()->m_model->addSceneModelForDiagrams(this,id);
    m_nID = STR2ID(id);
    if (m_nID == Uml::id_None)
        return false;
//     setName(qElement.attribute("name", "")); //TODO elv13 restore
    QString type = qElement.attribute("type", "0");
    m_Documentation = qElement.attribute("documentation", "");
    QString localid = qElement.attribute("localid", "0");
    // option state
    Settings::loadFromXMI(qElement, m_Options);
//     setBackgroundBrush(m_Options.uiState.backgroundColor); //TODO elv13 restore
//     setGridDotColor(m_Options.uiState.gridDotColor); //TODO elv13 restore
    //misc
//     QString showgrid = qElement.attribute("showgrid", "0");//TODO elv13 restore
//     m_layoutGrid->setVisible((bool)showgrid.toInt());//TODO elv13 restore

//     QString snapgrid = qElement.attribute("snapgrid", "0");//TODO elv13 restore
//     m_bUseSnapToGrid = (bool)snapgrid.toInt();//TODO elv13 restore

//     QString snapcsgrid = qElement.attribute("snapcsgrid", "0");//TODO elv13 restore
//     m_bUseSnapComponentSizeToGrid = (bool)snapcsgrid.toInt();//TODO elv13 restore

//     QString snapx = qElement.attribute("snapx", "10");//TODO elv13 restore
//     QString snapy = qElement.attribute("snapy", "10");//TODO elv13 restore
//     m_layoutGrid->setGridSpacing(snapx.toInt(), snapy.toInt());//TODO elv13 restore

//     QString zoom = qElement.attribute("zoom", "100");//TODO elv13 restore
//     activeView()->setZoom(zoom.toInt());//TODO elv13 restore

    /*QString height = qElement.attribute("canvasheight", QString("%1").arg(defaultCanvasSize));//TODO elv13 restore
    qreal canvasHeight = height.toDouble();

    QString width = qElement.attribute("canvaswidth", QString("%1").arg(defaultCanvasSize));
    qreal canvasWidth = width.toDouble();
    setSceneRect(0, 0, canvasWidth, canvasHeight);*/

    QString isOpen = qElement.attribute("isopen", "1");
    m_isOpen = (bool)isOpen.toInt();

    int nType = type.toInt();
    if (nType == -1 || nType >= 400) {
        // Pre 1.5.5 numeric values
        // Values of "type" were changed in 1.5.5 to merge with Settings::Diagram
        switch (nType) {
        case 400:
            m_Type = Uml::DiagramType::UseCase;
            break;
        case 401:
            m_Type = Uml::DiagramType::Collaboration;
            break;
        case 402:
            m_Type = Uml::DiagramType::Class;
            break;
        case 403:
            m_Type = Uml::DiagramType::Sequence;
            break;
        case 404:
            m_Type = Uml::DiagramType::State;
            break;
        case 405:
            m_Type = Uml::DiagramType::Activity;
            break;
        case 406:
            m_Type = Uml::DiagramType::Component;
            break;
        case 407:
            m_Type = Uml::DiagramType::Deployment;
            break;
        case 408:
            m_Type = Uml::DiagramType::EntityRelationship;
            break;
        default:
            m_Type = Uml::DiagramType::Undefined;
            break;
        }
    } else {
        m_Type = Uml::DiagramType::Value(nType);
    }
    m_nLocalID = STR2ID(localid);

    QDomNode node = qElement.firstChild();
    bool widgetsLoaded = false, messagesLoaded = false, associationsLoaded = false;
    while (!node.isNull()) {
        QDomElement element = node.toElement();
        if (!element.isNull()) {
            if (element.tagName() == "widgets")
                widgetsLoaded = loadWidgetsFromXMI(element);
            else if (element.tagName() == "messages")
                messagesLoaded = loadMessagesFromXMI(element);
            else if (element.tagName() == "associations")
                associationsLoaded = loadAssociationsFromXMI(element);
        }
        node = node.nextSibling();
    }

    if (!widgetsLoaded) {
        uWarning() << "failed UMLScene load on widgets";
        return false;
    }
    if (!messagesLoaded) {
        uWarning() << "failed UMLScene load on messages";
        return false;
    }
    if (!associationsLoaded) {
        uWarning() << "failed UMLScene load on associations";
        return false;
    }
    return true;
}

bool UMLSceneModel::loadWidgetsFromXMI(QDomElement & qElement)
{
    UMLWidget* widget = 0;
    QDomNode node = qElement.firstChild();
    QDomElement widgetElement = node.toElement();
    while (!widgetElement.isNull()) {
        widget = loadWidgetFromXMI(widgetElement);
        if (widget) {
            m_WidgetList.append(widget);
            // In the interest of best-effort loading, in case of a
            // (widget == NULL) we still go on.
            // The individual widget's loadFromXMI method should
            // already have generated an error message to tell the
            // user that something went wrong.
        }
        node = widgetElement.nextSibling();
        widgetElement = node.toElement();
    }

    return true;
}

/**
 * Loads a "widget" element from XMI, used by loadFromXMI() and the clipboard.
 */
UMLWidget* UMLSceneModel::loadWidgetFromXMI(QDomElement& widgetElement)
{
    if (!m_doc) {
        uWarning() << "m_doc is NULL";
        return 0L;
    }

    QString tag  = widgetElement.tagName();
    QString idstr  = widgetElement.attribute("xmi.id", "-1");
    UMLWidget* widget = Widget_Factory::makeWidgetFromXMI(tag, idstr/*, this*/);
    emit sigNewWidget(widget);

    if (widget == NULL)
        return NULL;
    if (!widget->loadFromXMI(widgetElement)) {
        delete widget;
        return 0;
    }
    return widget;
}

bool UMLSceneModel::loadMessagesFromXMI(QDomElement & qElement)
{
    MessageWidget * message = 0;
    QDomNode node = qElement.firstChild();
    QDomElement messageElement = node.toElement();
    while (!messageElement.isNull()) {
        QString tag = messageElement.tagName();
        DEBUG(DBG_SRC) << "tag = " << tag;
        if (tag == "messagewidget" ||
            tag == "UML:MessageWidget") {   // for bkwd compatibility
            message = new MessageWidget(Uml::sequence_message_asynchronous,
                                        Uml::id_Reserved);
            if (!message->loadFromXMI(messageElement)) {
                delete message;
                return false;
            }
//             addWidget(message);
            emit sigNewMessage(message);
            m_MessageList.append(message);
            FloatingTextWidget *ft = message->floatingTextWidget();
            if (ft)
                m_WidgetList.append(ft);
            else if (message->sequenceMessageType() != Uml::sequence_message_creation)
                DEBUG(DBG_SRC) << "floating text is NULL for message " << ID2STR(message->id());
        }
        node = messageElement.nextSibling();
        messageElement = node.toElement();
    }
    return true;
}

bool UMLSceneModel::loadAssociationsFromXMI(QDomElement & qElement)
{
    QDomNode node = qElement.firstChild();
    QDomElement assocElement = node.toElement();
    int countr = 0;
    while (!assocElement.isNull()) {
        QString tag = assocElement.tagName();
        if (tag == "assocwidget" ||
            tag == "UML:AssocWidget") {  // for bkwd compatibility
            countr++;
            AssociationWidget *assoc = new AssociationWidget();
//             addItem(assoc);
            if (!assoc->loadFromXMI(assocElement)) {
                uError() << "could not loadFromXMI association widget:"
                         << assoc << ", bad XMI file? Deleting from UMLScene.";
                delete assoc;
                /* return false;
                   Returning false here is a little harsh when the
                   rest of the diagram might load okay.
                 */
            } else {
                emit sigNewAssociation(assoc);
//                 if (!addAssociation(assoc, false)) {
//                     uError() << "Could not addAssociation(" << assoc << ") to UMLScene, deleting.";
//                     delete assoc;
//                     //return false; // soften error.. may not be that bad
//                 }
            }
        }
        node = assocElement.nextSibling();
        assocElement = node.toElement();
    }
    return true;
}


/**
 * Return a unique ID for the diagram.  Used by the @ref ObjectWidget class.
 *
 * @return Return a unique ID for the diagram.
 */
Uml::IDType UMLSceneModel::localID()
{
    m_nLocalID = UniqueID::gen();
    return m_nLocalID;
}



/**
 * Returns the ID of the diagram.
 */
Uml::IDType UMLSceneModel::ID() const
{
    return m_nID;
}

/**
 * Sets the ID of the diagram.
 */
void UMLSceneModel::setID(Uml::IDType id)
{
    m_nID = id;
}



/**
 * Returns the options being used.
 */
Settings::OptionState& UMLSceneModel::optionState()
{
    return m_Options;
}

/**
 * Sets the options to be used.
 */
void UMLSceneModel::setOptionState(const Settings::OptionState& options)
{
    m_Options = options;
}


/**
 * Returns the open state.
 * @return   when true diagram is shown to the user
 */
bool UMLSceneModel::isOpen() const
{
    return m_isOpen;
}

/**
 * Sets the flag 'isOpen'.
 * @param isOpen   flag indicating that the diagram is shown to the user
 */
void UMLSceneModel::setIsOpen(bool isOpen)
{
    m_isOpen = isOpen;
}

/**
 * Returns the type of the diagram.
 */
Uml::DiagramType UMLSceneModel::type() const
{
    return m_Type;
}

/**
 * Set the type of diagram.
 */
void UMLSceneModel::setType(Uml::DiagramType type)
{
    m_Type = type;
}



/**
 * Return the documentation of the diagram.
 */
QString UMLSceneModel::documentation() const
{
    return m_Documentation;
}

/**
 * Set the documentation of the diagram.
 */
void UMLSceneModel::setDocumentation(const QString &doc)
{
    m_Documentation = doc;
}

/**
 * Return the name of the diagram.
 */
QString UMLSceneModel::name() const
{
    return m_Name;
}

/**
 * Set the name of the diagram.
 */
void UMLSceneModel::setName(const QString &name)
{
    m_Name = name;
}

/**
 * Returns a reference to the association list.
 */
AssociationWidgetList& UMLSceneModel::associationList()
{
    return m_AssociationList;
}

/**
 * Returns a reference to the widget list.
 */
UMLWidgetList& UMLSceneModel::widgetList()
{
    return m_WidgetList;
}

/**
 * Returns a reference to the message list.
 */
MessageWidgetList& UMLSceneModel::messageList()
{
    return m_MessageList;
}



/**
 * Returns a List of all the UMLObjects(Use Cases, Concepts and Actors) in the View
 */
UMLObjectList UMLSceneModel::umlObjects()
{
    UMLObjectList list;
    foreach(UMLWidget* w,  widgetList()) {

        switch (w->baseType()) { //use switch for easy future expansion
        case WidgetBase::wt_Actor:
        case WidgetBase::wt_Class:
        case WidgetBase::wt_Interface:
        case WidgetBase::wt_Package:
        case WidgetBase::wt_Component:
        case WidgetBase::wt_Node:
        case WidgetBase::wt_Artifact:
        case WidgetBase::wt_UseCase:
        case WidgetBase::wt_Object:
            list.append(w->umlObject());
            break;
        default:
            break;
        }
    }
    return list;
}