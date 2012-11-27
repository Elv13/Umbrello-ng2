#include "projectdockmodel.h"

ProjectDockModel::ProjectDockModel(QObject* parent) : QAbstractItemModel(parent)
{
    
}

ProjectDockModel::~ProjectDockModel()
{
    
}

int ProjectDockModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant ProjectDockModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex ProjectDockModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex ProjectDockModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ProjectDockModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool ProjectDockModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return false;
}

QVariant ProjectDockModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}
