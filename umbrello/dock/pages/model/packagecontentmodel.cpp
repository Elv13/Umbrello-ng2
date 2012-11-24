#include "packagecontentmodel.h"

#include "classifier.h"

PackageContentModel::PackageContentModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

PackageContentModel::~PackageContentModel()
{
    
}

int PackageContentModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant PackageContentModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex PackageContentModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
}

QModelIndex PackageContentModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int PackageContentModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool PackageContentModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void PackageContentModel::setCurrentObject(UMLObject* o)
{
    
}
