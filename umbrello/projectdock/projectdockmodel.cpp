#include "projectdockmodel.h"

#include <QtCore/QDebug>
#include "umllistview.h" //TODO remove
#include "umllistmodel.h"
#include "uml.h"
#include "umlwidget.h"

ProjectDockModel::ProjectDockModel(QObject* parent) : QAbstractItemModel(parent)
{
    connect(UMLApp::app()->listView()->m_model,SIGNAL(sigDiagramListChanged()),this,SLOT(slotDiagramListChanged()));
}

ProjectDockModel::~ProjectDockModel()
{
    
}

int ProjectDockModel::columnCount(const QModelIndex& parent) const
{
    return 1;
}

QVariant ProjectDockModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            if (index.parent().isValid() || index.internalId() == 2) {
                UmlElementNode *parentItem = UMLApp::app()->listView()->m_model->diagrams()[index.parent().row()];
                if (parentItem && parentItem->model) {
                    return QVariant(parentItem->model->widgetList()[index.row()]->name());
                }
                else
                    return QVariant("dummy");
            }
            else if (UMLApp::app()->listView()->m_model->diagrams().size() > index.row())
                return QVariant(UMLApp::app()->listView()->m_model->diagrams()[index.row()]->item->text(0));
    }
    return QVariant();
}

QModelIndex ProjectDockModel::index(int row, int column, const QModelIndex& parent) const
{

    UmlElementNode *parentItem;

    if (!parent.isValid())
        parentItem = 0;
    else
        parentItem = static_cast<UmlElementNode*>(parent.internalPointer());

    if (!parentItem) {
        if (UMLApp::app()->listView()->m_model->diagrams().size() > row)
            return createIndex(row, column, UMLApp::app()->listView()->m_model->diagrams()[row]);
        return QModelIndex();
    }
    else {
        UmlElementNode* elem = new UmlElementNode;
        elem->row = row;
        elem->parent = parentItem;
        return createIndex(row, column, elem);
    }
    return QModelIndex();
}

QModelIndex ProjectDockModel::parent(const QModelIndex& index ) const
{
    if (!index.isValid())
        return QModelIndex();

    UmlElementNode *childItem = static_cast<UmlElementNode*>(index.internalPointer());

    if (!childItem || childItem->isTopLevel)
        return QModelIndex(); //No parent

    return createIndex(childItem->parent->row, 0, childItem->parent);
}

int ProjectDockModel::rowCount(const QModelIndex& parent) const
{
    UmlElementNode *parentItem;
    if (parent.column() > 0 || parent.parent().isValid()) //TODO fix
        return 0;

    if (!parent.isValid())
        parentItem = 0;
    else
        parentItem = static_cast<UmlElementNode*>(parent.internalPointer());

    return (!parentItem)?UMLApp::app()->listView()->m_model->diagrams().size():/*parentItem->childs.size()*/((parentItem->model)?parentItem->model->widgetList().size():3);
}

bool ProjectDockModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return false;
}

QVariant ProjectDockModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            return QVariant("Diagrams");
    }
    return QVariant();
}

void ProjectDockModel::slotDiagramListChanged()
{
    emit dataChanged(index(0,0),index(rowCount(),3));
    emit layoutChanged();
}