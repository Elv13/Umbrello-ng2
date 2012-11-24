#include "enumliteralsmodel.h"

#include "classifier.h"

EnumLiteralsModel::EnumLiteralsModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

EnumLiteralsModel::~EnumLiteralsModel()
{
    
}

int EnumLiteralsModel::columnCount(const QModelIndex& parent) const
{
    return 0;
}

QVariant EnumLiteralsModel::data(const QModelIndex& index, int role) const
{
    return QVariant();
}

QModelIndex EnumLiteralsModel::index(int row, int column, const QModelIndex& parent) const
{
    return QModelIndex();
}

QModelIndex EnumLiteralsModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int EnumLiteralsModel::rowCount(const QModelIndex& parent) const
{
    return 0;
}

bool EnumLiteralsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void EnumLiteralsModel::setCurrentObject(UMLObject* o)
{
    
}
