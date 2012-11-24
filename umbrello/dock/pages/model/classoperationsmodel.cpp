#include "classoperationsmodel.h"

#include "classifier.h"

ClassOperationsModel::ClassOperationsModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassOperationsModel::~ClassOperationsModel()
{
    
}

int ClassOperationsModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant ClassOperationsModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex ClassOperationsModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
}

QModelIndex ClassOperationsModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassOperationsModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool ClassOperationsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void ClassOperationsModel::setCurrentObject(UMLObject* o)
{
    
}
