#include "enumliteralsmodel.h"

#include "classifier.h"
#include "enum.h"

EnumLiteralsModel::EnumLiteralsModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

EnumLiteralsModel::~EnumLiteralsModel()
{
    
}

int EnumLiteralsModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}

QVariant EnumLiteralsModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case EnumLiteralsModel::Name:
                    return QVariant(m_pData->getFilteredList(UMLObject::ot_EnumLiteral)[index.row()]->name());
                case EnumLiteralsModel::Value:
                    return QVariant("TODO"/*m_pData->getFilteredList(UMLObject::ot_EnumLiteral)[index.row()]->defaultValue()*/);
            }
            break;
    }

    return QVariant();
}

Qt::ItemFlags EnumLiteralsModel::flags(const QModelIndex& index) const {
   if (index.column() == 0)
      return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
   return QAbstractItemModel::flags(index);
}

QModelIndex EnumLiteralsModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex EnumLiteralsModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int EnumLiteralsModel::rowCount(const QModelIndex& parent) const
{
    return (m_pData)?(m_pData->getFilteredList(UMLObject::ot_EnumLiteral).size()):0;
}

bool EnumLiteralsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void EnumLiteralsModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLEnum*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}

QVariant EnumLiteralsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();
    else if (role == Qt::DisplayRole) {
        switch (section) {
            case EnumLiteralsModel::Name:
                return QVariant( "Name"    );
            case EnumLiteralsModel::Value:
                return QVariant( "Value"   );
        }
    }
    return QVariant();
}