#include "classattributesmodel.h"

#include "classifier.h"
#include <QtCore/QDebug>

ClassAttributesModel::ClassAttributesModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassAttributesModel::~ClassAttributesModel()
{
    
}

int ClassAttributesModel::columnCount(const QModelIndex& parent) const
{
    return 7;
}

QVariant ClassAttributesModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case ClassAttributesModel::Name:
                    return QVariant(m_pData->getAttributeList()[index.row()]->name());
                    break;
                case ClassAttributesModel::Type:
                    return QVariant(m_pData->getAttributeList()[index.row()]->getTypeName());
                    break;
                case ClassAttributesModel::InitialValue:
                    return QVariant(m_pData->getAttributeList()[index.row()]->getInitialValue());
                    break;
                case ClassAttributesModel::Visibility:
                    return QVariant(m_pData->getAttributeList()[index.row()]->visibility());
                    break;
                case ClassAttributesModel::StereotypeName:
                    return QVariant(m_pData->getAttributeList()[index.row()]->stereotype());
                    break;
                case ClassAttributesModel::Static:
                    return QVariant(m_pData->getAttributeList()[index.row()]->isStatic());
                    break;
                case ClassAttributesModel::Documentation:
                    return QVariant(m_pData->getAttributeList()[index.row()]->doc());
                    break;
            }
            break;
    }

    return QVariant();
}

QModelIndex ClassAttributesModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex ClassAttributesModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassAttributesModel::rowCount(const QModelIndex& parent) const
{
    return (m_pData)?(m_pData->getAttributeList().size()):0;
}

bool ClassAttributesModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    return 0;
}

void ClassAttributesModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLClassifier*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}

QVariant ClassAttributesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();
    else if (role == Qt::DisplayRole) {
        switch (section) {
            case 0:
                return QVariant("Name");
            case 1:
                return QVariant("Type");
            case 2:
                return QVariant("Initial value");
            case 3:
                return QVariant("Visibility");
            case 4:
                return QVariant("Steotype Name");
            case 5:
                return QVariant("S");
            case 6:
                return QVariant("Doc");
        }
    }
    return QVariant();
}