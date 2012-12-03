/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2002-2011                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

#ifndef UMLLISTVIEW_H
#define UMLLISTVIEW_H

#include "umllistmodel.h"
#include "basictypes.h"
#include "umllistviewitem.h"
#include "umllistviewitemlist.h"
#include "icon_utils.h"
#include "umlobject.h"

#include <QDomDocument>
#include <QDomElement>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class QEvent;
class QMouseEvent;
class QFocusEvent;
class QKeyEvent;
class QDropEvent;
class IDChangeLog;
class ListPopupMenu;
class UMLClassifier;
class UMLDoc;
class UMLView;
class UMLClassifierListItem;
class UMLDragData;

/**
 * This is one of the main classes used in this program.
 * Information is displayed here in a tree view. No objects are created
 * here. A call to @ref UMLDoc make any additions/deletion or updates to
 * objects. This class will then wait for a signal before updating the tree view.
 *
 * @short  Displays the list view for the program.
 * @author Paul Hensgen    <phensgen@techie.com>
 * Bugs and comments to uml-devel@lists.sf.net or http://bugs.kde.org
 */
class UMLListView : public QTreeWidget
{
    Q_OBJECT
public:
    UMLListView(QWidget *parent = 0);
    ~UMLListView();

    void setDocument(UMLDoc * doc);
    UMLDoc * document() const;

    void init();
    void clean();

    void setView(UMLView* view);

    void setTitle(int column, const QString &text);

    UMLListViewItemList selectedItems();
    UMLListViewItemList selectedItemsRoot();
    int selectedItemsCount();

    void startUpdate();
    void endUpdate();

    UMLListViewItem* createDiagramItem(UMLView *view);

    UMLListViewItem* createItem(UMLListViewItem& Data, IDChangeLog& IDChanges,
                                UMLListViewItem* parent = 0);
    bool createItem(UMLListViewItem *item);

    UMLListViewItem* findFolderForDiagram(Uml::DiagramType dt);

    UMLListViewItem* determineParentItem(UMLObject* object) const;
    UMLListViewItem* determineParentItem(UMLListViewItem::ListViewType lvt) const;

    static bool mayHaveChildItems(UMLObject::ObjectType type);

    void addNewItem(UMLListViewItem * parent, UMLListViewItem::ListViewType type);

    UMLListViewItem *rootView(UMLListViewItem::ListViewType type);

    void changeIconOf(UMLObject *o, Icon_Utils::IconType to);

    UMLObject *createUMLObject(UMLListViewItem * item, UMLObject::ObjectType type);
    bool createChildUMLObject(UMLListViewItem * item, UMLObject::ObjectType type);
    UMLView* createDiagram(UMLListViewItem * item, Uml::DiagramType type);

    QString uniqueDiagramName(Uml::DiagramType type);

    bool isUnique(UMLListViewItem * item, const QString &name);

    void startRename(UMLListViewItem * item);
    void cancelRename(UMLListViewItem * item);
    void endRename(UMLListViewItem * item);

    void setSelected(UMLListViewItem * item, bool state) { setItemSelected((QTreeWidgetItem*)item,state);  }
    void setStartedCut(bool startedCut);
    void setStartedCopy(bool startedCopy);
    bool startedCopy() const;

    bool itemRenamed(UMLListViewItem* item, int col);

    void closeDatatypesFolder();

    UMLListViewItem *theRootView() { return m_model->m_rv; }
    UMLListViewItem *theLogicalView() { return m_model->m_lv[Uml::ModelType::Logical]; }
    UMLListViewItem *theUseCaseView() { return m_model->m_lv[Uml::ModelType::UseCase]; }
    UMLListViewItem *theComponentView() { return m_model->m_lv[Uml::ModelType::Component]; }
    UMLListViewItem *theDeploymentView() { return m_model->m_lv[Uml::ModelType::Deployment]; }
    UMLListViewItem *theDatatypeFolder() { return m_model->m_datatypeFolder; }

    UMLListViewItem::ListViewType rootViewType(UMLListViewItem *item);

    void saveToXMI(QDomDocument & qDoc, QDomElement & qElement);
//     bool loadFromXMI(QDomElement & element);
//     bool loadChildrenFromXMI(UMLListViewItem * parent, QDomElement & element);

    friend QDebug operator<<(QDebug out, const UMLListView& view);

protected:
    bool event(QEvent *e);
    bool eventFilter(QObject *o, QEvent *e);
    void mouseReleaseEvent(QMouseEvent *me);
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
    void mouseDoubleClickEvent(QMouseEvent *me);
    void focusOutEvent (QFocusEvent *fe);

    UMLDragData* getDragData();

    bool acceptDrag(QDropEvent* event) const;
    void keyPressEvent(QKeyEvent* ke);
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dropEvent(QDropEvent* event);

    static bool isExpandable(UMLListViewItem::ListViewType lvt);

    void deleteChildrenOf(UMLListViewItem *parent);

    bool deleteItem(UMLListViewItem *temp);


public slots:
    void slotDiagramCreated(Uml::IDType id);
    void slotDiagramRenamed(Uml::IDType id);
    void slotDiagramRemoved(Uml::IDType id);
    void slotObjectCreated(UMLObject* object);
    void slotObjectRemoved(UMLObject* object);

    void popupMenuSel(QAction* action);

    void slotDropped(QDropEvent* de, UMLListViewItem* parent, UMLListViewItem* item);

    void expandAll(UMLListViewItem *item);
    void collapseAll(UMLListViewItem *item);

    void slotCutSuccessful();

protected slots:
    void slotItemChanged(QTreeWidgetItem *, int);
    void slotItemSelectionChanged();
    void slotExpanded(QTreeWidgetItem* item);
    void slotCollapsed(QTreeWidgetItem* item);

private:

    void setBackgroundColor(const QColor & color);

    ListPopupMenu*   m_menu;
    bool             m_bStartedCut;
    bool             m_bStartedCopy;
    bool m_bRenameInProgress;
    QPoint m_dragStartPosition;
    UMLListViewItem* m_editItem;
public: //TODO change this
    UMLListModel*    m_model;
};

#endif
