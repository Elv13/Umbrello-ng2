#ifndef UML_LIST_MODEL_H
#define UML_LIST_MODEL_H

#include <QDomDocument>
#include <QDomElement>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "umllistviewitem.h"
#include "umlscenemodel.h"

class UMLDoc;
class UMLClassifier;
class UMLClassifierListItem;
class UMLView;

struct UmlElementNode {
    UmlElementNode() : item(0),parent(0),isTopLevel(0){}
    QVector<UmlElementNode*> childs;
    UMLListViewItem *item;
    UmlElementNode* parent;
    UMLSceneModel* model;
    bool isTopLevel;
    int row;
};

class UMLListModel : public QObject {
    Q_OBJECT
public:
    UMLListModel();
    ~UMLListModel();
    bool loadFromXMI(QDomElement & element);
    bool loadChildrenFromXMI(UMLListViewItem * parent, QDomElement & element);
    UMLListViewItem * findItem(Uml::IDType id);
    UMLListViewItem * moveObject(Uml::IDType srcId, UMLListViewItem::ListViewType srcType,
                                 UMLListViewItem *newParent);

    void addAtContainer(UMLListViewItem *item, UMLListViewItem *parent);
    UMLListViewItem * findUMLObject(const UMLObject *p) const;
    void childObjectAdded(UMLClassifierListItem* child, UMLClassifier* parent);
    UMLListViewItem* recursiveSearchForView(UMLListViewItem* folder,
                                            UMLListViewItem::ListViewType type, Uml::IDType id);

    UMLListViewItem * findView(UMLView *v);

    UMLListViewItem * findUMLObjectInFolder(UMLListViewItem *folder, UMLObject *obj);
    
    //Tree model
    UMLListViewItem * topLevelItem(int i) const;
    int topLevelItemCount() const;
    void addTopLevelItem(UMLListViewItem* item);
    
    //Getter
    
    QVector<UmlElementNode*> diagrams() {return m_diagrams;}
    
    //Setter
    void addSceneModelForDiagrams(UMLSceneModel* sceneModel,QString id);
private:
    QVector<UmlElementNode*> m_nodes;
    QVector<UmlElementNode*> m_diagrams;
    QHash<QString,UmlElementNode*> m_diagramsById;
    
public slots:
    void connectNewObjectsSlots(UMLObject* object);

private slots:
    void childObjectAdded(UMLClassifierListItem* obj);
    void childObjectRemoved(UMLClassifierListItem* obj);

    void slotObjectChanged();
    
// protected:
public: //TODO make private
    UMLDoc*          m_doc;
    UMLListViewItem* m_rv;         ///< root view (home)
    UMLListViewItem* m_lv[Uml::ModelType::N_MODELTYPES];  ///< predefined list view roots
    UMLListViewItem* m_datatypeFolder;
    bool m_bCreatingChildObject;  ///< when creating an attribute or an operation to stop it adding a second listViewItem

signals:
    void sigDiagramListChanged();
};

#endif