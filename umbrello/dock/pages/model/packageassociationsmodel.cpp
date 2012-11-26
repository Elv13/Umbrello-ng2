#include "packageassociationsmodel.h"

#include "classifier.h"
#include "package.h"

PackageAssociationsModel::PackageAssociationsModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

PackageAssociationsModel::~PackageAssociationsModel()
{
    
}

int PackageAssociationsModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant PackageAssociationsModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case PackageAssociationsModel::Name:
                    return QVariant("TODO");
                    break;
                case PackageAssociationsModel::Direction:
                    return QVariant("TODO");
                    break;
                case PackageAssociationsModel::Buddy:
                    return QVariant("TODO");
                    break;
                case PackageAssociationsModel::Type:
                    return QVariant("TODO");
                    break;
                case PackageAssociationsModel::Doc:
                    return QVariant("TODO");
                    break;
            }
            break;
    }
    return QVariant();
}

QModelIndex PackageAssociationsModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex PackageAssociationsModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int PackageAssociationsModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool PackageAssociationsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void PackageAssociationsModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLPackage*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}

QVariant PackageAssociationsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();
    else if (role == Qt::DisplayRole) {
        switch (section) {
            case PackageAssociationsModel::Name:
                return QVariant("Name");
            case PackageAssociationsModel::Direction:
                return QVariant("Direction");
            case PackageAssociationsModel::Buddy:
                return QVariant("Buddy");
            case PackageAssociationsModel::Type:
                return QVariant("Type");
            case PackageAssociationsModel::Doc:
                return QVariant("Doc");
        }
    }
    return QVariant();
}