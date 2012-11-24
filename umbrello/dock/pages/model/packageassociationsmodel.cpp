#include "packageassociationsmodel.h"

#include "classifier.h"

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
    return QVariant();
}

QModelIndex PackageAssociationsModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
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
    
}
