#ifndef UML_SCENE_MODEL_H
#define UML_SCENE_MODEL_H

#include <QDomDocument>
#include <QDomElement>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "umllistviewitem.h"
#include "umlobject.h"
#include "basictypes.h"
#include "optionstate.h"
#include "umlwidgetlist.h"
#include "messagewidgetlist.h"
#include "associationwidgetlist.h"
#include "umlobjectlist.h"

class UMLDoc;
class UMLClassifier;
class UMLClassifierListItem;
class UMLView;
class AssociationWidget;

class UMLSceneModel : public QObject {
    Q_OBJECT
public:
    UMLSceneModel();
    ~UMLSceneModel();
    
    
    virtual bool loadFromXMI(QDomElement & qElement);
    UMLWidget* loadWidgetFromXMI(QDomElement& widgetElement);
    
    
    // Methods and members related to loading/saving

    bool loadWidgetsFromXMI(QDomElement & qElement);
    bool loadMessagesFromXMI(QDomElement & qElement);
    bool loadAssociationsFromXMI(QDomElement & qElement);

    Settings::OptionState& optionState();
    void setOptionState(const Settings::OptionState& options);

    Uml::IDType localID();

    Uml::IDType ID() const;
    void setID(Uml::IDType id);

    bool isOpen() const;
    void setIsOpen(bool isOpen);

    Uml::DiagramType type() const;
    void setType(Uml::DiagramType type);

    QString documentation() const;
    void setDocumentation(const QString &doc);

    QString name() const;
    void setName(const QString &name);

    UMLDoc* doc() const {return m_doc;}
    void setDoc(UMLDoc* doc) {m_doc = doc;}

    UMLWidgetList& widgetList();
    MessageWidgetList& messageList();
    UMLObjectList umlObjects();
    AssociationWidgetList& associationList();
    
private:
    
    Uml::IDType m_nID;                ///< The ID of the view. Allocated by @ref UMLDoc.
    QString m_Documentation;          ///< The documentation of the diagram.
    Settings::OptionState m_Options;  ///< Options used by view.z
    bool m_isOpen;  ///< Flag is set to true when diagram is open, i.e. shown to the user.
    UMLDoc* m_doc;                  ///< Pointer to the UMLDoc.
    UMLWidgetList m_WidgetList;       ///< All the UMLWidgets on the diagram.
    MessageWidgetList m_MessageList;  ///< All the message widgets on the diagram.
    AssociationWidgetList m_AssociationList;  ///< All the AssociationWidgets on the diagram.

    /**
     * Contains the unique ID to allocate to a widget that needs an
     * ID for the view.  @ref ObjectWidget is an example of this.
     */
    Uml::IDType m_nLocalID;

    Uml::DiagramType m_Type;          ///< The type of diagram to represent.
    QString m_Name;                   ///< The name of the diagram.
    
private:
//     void sigDiagramListChanged();
    
signals:
    void sigNewWidget(UMLWidget* w);
    void sigNewMessage(UMLWidget* w);
    void sigNewAssociation(AssociationWidget* w);
};

#endif