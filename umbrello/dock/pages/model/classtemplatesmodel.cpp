#include "classtemplatesmodel.h"

#include "classifier.h"

ClassTemplatesModel::ClassTemplatesModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassTemplatesModel::~ClassTemplatesModel()
{
    
}

int ClassTemplatesModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant ClassTemplatesModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex ClassTemplatesModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
}

QModelIndex ClassTemplatesModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassTemplatesModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool ClassTemplatesModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void ClassTemplatesModel::setCurrentObject(UMLObject* o)
{
    
}
