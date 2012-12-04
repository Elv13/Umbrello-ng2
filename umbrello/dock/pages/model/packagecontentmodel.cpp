#include "packagecontentmodel.h"

#include "classifier.h"
#include "package.h"

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
//     switch (role) {
//         case Qt::DisplayRole:
//             switch (index.column()) {
//                 case 
//             }
//             break;
//     }

    return QVariant();
}

Qt::ItemFlags PackageContentModel::flags(const QModelIndex& index) const {
   if (index.column() == 0)
      return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
   return QAbstractItemModel::flags(index);
}

QModelIndex PackageContentModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex PackageContentModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int PackageContentModel::rowCount(const QModelIndex& parent) const
{
    return (m_pData)?(m_pData->containedObjects().size()):0;
}

bool PackageContentModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}


void PackageContentModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLPackage*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}

QVariant PackageContentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
//     if (orientation == Qt::Vertical)
//         return QVariant();
//     else if (role == Qt::DisplayRole) {
//         switch (section) {
//             case PackageContentModel::Name:
//                 return QVariant( "Name"          );
//             case PackageContentModel::Type:
//                 return QVariant( "Type"          );
//             case PackageContentModel::Stereotype:
//                 return QVariant( "Stereotype" );
//         }
//     }
    return QVariant();
}
