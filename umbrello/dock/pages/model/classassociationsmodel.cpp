#include "classassociationsmodel.h"

#include "classifier.h"

ClassAssociationsModel::ClassAssociationsModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassAssociationsModel::~ClassAssociationsModel()
{
    
}

int ClassAssociationsModel::columnCount(const QModelIndex& parent) const
{
    return 5;
}

QVariant ClassAssociationsModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case ClassAssociationsModel::Name:
                    return QVariant("TODO");
                    break;
                case ClassAssociationsModel::Direction:
                    return QVariant("TODO");
                    break;
                case ClassAssociationsModel::Buddy:
                    return QVariant("TODO");
                    break;
                case ClassAssociationsModel::Type:
                    return QVariant("TODO");
                    break;
                case ClassAssociationsModel::Doc:
                    return QVariant("TODO");
                    break;
            }
            break;
    }

    return QVariant();
}

Qt::ItemFlags ClassAssociationsModel::flags(const QModelIndex& index) const {
   if (index.column() == 0)
      return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
   return QAbstractItemModel::flags(index);
}


QModelIndex ClassAssociationsModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex ClassAssociationsModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassAssociationsModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool ClassAssociationsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void ClassAssociationsModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLClassifier*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}

QVariant ClassAssociationsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();
    else if (role == Qt::DisplayRole) {
        switch (section) {
            case ClassAssociationsModel::Name:
                return QVariant("Name");
            case ClassAssociationsModel::Direction:
                return QVariant("Direction");
            case ClassAssociationsModel::Buddy:
                return QVariant("Buddy");
            case ClassAssociationsModel::Type:
                return QVariant("Type");
            case ClassAssociationsModel::Doc:
                return QVariant("Doc");
        }
    }
    return QVariant();
}