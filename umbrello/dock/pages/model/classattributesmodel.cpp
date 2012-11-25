#include "classattributesmodel.h"

#include "classifier.h"

ClassAttributesModel::ClassAttributesModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassAttributesModel::~ClassAttributesModel()
{
    
}

int ClassAttributesModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant ClassAttributesModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex ClassAttributesModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
}

QModelIndex ClassAttributesModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassAttributesModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool ClassAttributesModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}

void ClassAttributesModel::setCurrentObject(UMLObject* o)
{
    
}