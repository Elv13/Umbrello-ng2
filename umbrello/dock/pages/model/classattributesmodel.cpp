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

QVariant ClassAttributesModel::privData(const QModelIndex& index) const
{
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
            return QVariant();
            break;
        case ClassAttributesModel::Documentation:
            return QVariant(m_pData->getAttributeList()[index.row()]->doc());
            break;
    }
    return QVariant();
}

QVariant ClassAttributesModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            return privData(index);
            break;
        case Qt::EditRole:
            return privData(index);
            break;
        case Qt::CheckStateRole:
            switch (index.column()) {
                case ClassAttributesModel::Static:
                    return QVariant(m_pData->getAttributeList()[index.row()]->isStatic()?Qt::Checked:Qt::Unchecked);
                default:
                    return QVariant();
            }
    }

    return QVariant();
}

Qt::ItemFlags ClassAttributesModel::flags(const QModelIndex& index) const {
   switch (index.column()) {
        case ClassAttributesModel::Name:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassAttributesModel::Type:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassAttributesModel::InitialValue:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassAttributesModel::Visibility:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassAttributesModel::StereotypeName:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassAttributesModel::Static:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
            break;
        case ClassAttributesModel::Documentation:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
    }
   return QAbstractItemModel::flags(index);
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
    switch (index.column()) {
        case ClassAttributesModel::Name:
            m_pData->getAttributeList()[index.row()]->setName(value.toString());
            return true;
            break;
        case ClassAttributesModel::Type:
            m_pData->getAttributeList()[index.row()]->setTypeName(value.toString());
            return true;
            break;
        case ClassAttributesModel::InitialValue:
            m_pData->getAttributeList()[index.row()]->setInitialValue(value.toString());
            return true;
            break;
        case ClassAttributesModel::Visibility:
            m_pData->getAttributeList()[index.row()]->setVisibility((Uml::Visibility::Value)value.toInt());
            return true;
            break;
        case ClassAttributesModel::StereotypeName:
            m_pData->getAttributeList()[index.row()]->setStereotype(value.toString());
            return true;
            break;
        case ClassAttributesModel::Static:
            m_pData->getAttributeList()[index.row()]->setStatic(value == Qt::Checked);
            return true;
            break;
        case ClassAttributesModel::Documentation:
            m_pData->getAttributeList()[index.row()]->setDoc(value.toString());
            return true;
            break;
    }
    return false;
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
            case ClassAttributesModel::Name:
                return QVariant( "Name"          );
            case ClassAttributesModel::Type:
                return QVariant( "Type"          );
            case ClassAttributesModel::InitialValue:
                return QVariant( "Initial value" );
            case ClassAttributesModel::Visibility:
                return QVariant( "Visibility"    );
            case ClassAttributesModel::StereotypeName:
                return QVariant( "Steotype Name" );
            case ClassAttributesModel::Static:
                return QVariant( "S"             );
            case ClassAttributesModel::Documentation:
                return QVariant( "Doc"           );
        }
    }
    return QVariant();
}