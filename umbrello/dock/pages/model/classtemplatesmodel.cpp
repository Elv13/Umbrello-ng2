#include "classtemplatesmodel.h"

#include "classifier.h"
#include "template.h"

ClassTemplatesModel::ClassTemplatesModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassTemplatesModel::~ClassTemplatesModel()
{
    
}

int ClassTemplatesModel::columnCount(const QModelIndex& parent) const
{
    return 3;
}

QVariant ClassTemplatesModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case ClassTemplatesModel::Name:
                    return QVariant(m_pData->getTemplateList()[index.row()]->name());
                    break;
                case ClassTemplatesModel::Type:
                    return QVariant(m_pData->getTemplateList()[index.row()]->getTypeName());
                    break;
                case ClassTemplatesModel::Stereotype:
                    return QVariant(m_pData->getTemplateList()[index.row()]->stereotype());
                    break;
            }
            break;
    }

    return QVariant();
}

Qt::ItemFlags ClassTemplatesModel::flags(const QModelIndex& index) const {
   if (index.column() == 0)
      return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
   return QAbstractItemModel::flags(index);
}

QModelIndex ClassTemplatesModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex ClassTemplatesModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassTemplatesModel::rowCount(const QModelIndex& parent) const
{
    return (m_pData)?(m_pData->getTemplateList().size()):0;
}

bool ClassTemplatesModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void ClassTemplatesModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLClassifier*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}

QVariant ClassTemplatesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();
    else if (role == Qt::DisplayRole) {
        switch (section) {
            case ClassTemplatesModel::Name:
                return QVariant( "Name"          );
            case ClassTemplatesModel::Type:
                return QVariant( "Type"          );
            case ClassTemplatesModel::Stereotype:
                return QVariant( "Stereotype" );
        }
    }
    return QVariant();
}