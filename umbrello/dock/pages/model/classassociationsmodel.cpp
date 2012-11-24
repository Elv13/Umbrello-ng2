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
    return 0;
}

QVariant ClassAssociationsModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex ClassAssociationsModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
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
    
}
