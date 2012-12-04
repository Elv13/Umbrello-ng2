#include "classoperationsmodel.h"

#include "classifier.h"
#include "operation.h"

ClassOperationsModel::ClassOperationsModel(QObject* parent) : QAbstractTableModel(parent),m_pData(0)
{
    
}

ClassOperationsModel::~ClassOperationsModel()
{
    
}

int ClassOperationsModel::columnCount(const QModelIndex& parent) const
{
    return 10;
}

QVariant ClassOperationsModel::privData(const QModelIndex& index) const
{
    switch (index.column()) {
        case ClassOperationsModel::Name:
            return QVariant(m_pData->getOpList()[index.row()]->name());
            break;
        case ClassOperationsModel::Parameters:
            return QVariant("TODO");
            break;
        case ClassOperationsModel::Type:
            return QVariant(m_pData->getOpList()[index.row()]->getTypeName());
            break;
        case ClassOperationsModel::Visibility:
            return QVariant(m_pData->getOpList()[index.row()]->visibility());
            break;
        case ClassOperationsModel::Steotype:
            return QVariant(m_pData->getOpList()[index.row()]->stereotype());
            break;
        case ClassOperationsModel::Static:
            return QVariant();
            break;
        case ClassOperationsModel::Abstract:
            return QVariant();
            break;
        case ClassOperationsModel::Constant:
            return QVariant();
            break;
        case ClassOperationsModel::Documentation:
            return QVariant(m_pData->getOpList()[index.row()]->doc());
            break;
        case ClassOperationsModel::SourceCode:
            return QVariant("TODO");
            break;
    }
    return QVariant();
}

QVariant ClassOperationsModel::data(const QModelIndex& index, int role) const
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
                case ClassOperationsModel::Static:
                    return QVariant(m_pData->getOpList()[index.row()]->isStatic()?Qt::Checked:Qt::Unchecked);
                    break;
                case ClassOperationsModel::Abstract:
                    return QVariant(m_pData->getOpList()[index.row()]->isAbstract()?Qt::Checked:Qt::Unchecked);
                    break;
                case ClassOperationsModel::Constant:
                    return QVariant(m_pData->getOpList()[index.row()]->getConst()?Qt::Checked:Qt::Unchecked);
                    break;
                default:
                    return QVariant();
            }
    }

    return QVariant();
}

Qt::ItemFlags ClassOperationsModel::flags(const QModelIndex& index) const {
//    if (index.column() == 0)
//       return QAbstractItemModel::flags(index) | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    switch (index.column()) {
        case ClassOperationsModel::Name:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassOperationsModel::Parameters:
            return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassOperationsModel::Type:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassOperationsModel::Visibility:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassOperationsModel::Steotype:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassOperationsModel::Static:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
            break;
        case ClassOperationsModel::Abstract:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
            break;
        case ClassOperationsModel::Constant:
            return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
            break;
        case ClassOperationsModel::Documentation:
            return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
        case ClassOperationsModel::SourceCode:
            return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
            break;
    }
   return QAbstractItemModel::flags(index);
}

QModelIndex ClassOperationsModel::index(int row, int column, const QModelIndex& parent) const
{
    return createIndex(row,column);
}

QModelIndex ClassOperationsModel::parent(const QModelIndex& index ) const
{
    return QModelIndex();
}

int ClassOperationsModel::rowCount(const QModelIndex& parent) const
{
    return (m_pData)?(m_pData->getOpList().size()):0;
}

bool ClassOperationsModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    switch (index.column()) {
        case ClassOperationsModel::Name:
            m_pData->getOpList()[index.row()]->setName(value.toString());
            return true;
            break;
        case ClassOperationsModel::Parameters:
//             return QVariant("TODO");
            return false;
            break;
        case ClassOperationsModel::Type:
            m_pData->getOpList()[index.row()]->setTypeName(value.toString());
            return true;
            break;
        case ClassOperationsModel::Visibility:
            m_pData->getOpList()[index.row()]->setVisibility((Uml::Visibility::Value)value.toInt());
            return true;
            break;
        case ClassOperationsModel::Steotype:
            m_pData->getOpList()[index.row()]->setStereotype(value.toString());
            return true;
            break;
        case ClassOperationsModel::Static:
            m_pData->getOpList()[index.row()]->setStatic((value==Qt::Checked));
            break;
        case ClassOperationsModel::Abstract:
            m_pData->getOpList()[index.row()]->setAbstract((value==Qt::Checked));
            break;
        case ClassOperationsModel::Constant:
            m_pData->getOpList()[index.row()]->setConst((value==Qt::Checked));
            break;
        case ClassOperationsModel::Documentation:
            m_pData->getOpList()[index.row()]->setDoc(value.toString());
            return true;
            break;
        case ClassOperationsModel::SourceCode:
//             return QVariant("TODO");
            return false;
            break;
    }
    return 0;
}


void ClassOperationsModel::setCurrentObject(UMLObject* o)
{
    m_pData = qobject_cast<UMLClassifier*>(o);
    if (m_pData) {
        emit dataChanged(index(0,0),index(rowCount(),3));
        emit layoutChanged();
    }
}


QVariant ClassOperationsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();
    else if (role == Qt::DisplayRole) {
        switch (section) {
            case 0:
                return QVariant("Name");
            case 1:
                return QVariant("Parameters");
            case 2:
                return QVariant("Type");
            case 3:
                return QVariant("Visibility");
            case 4:
                return QVariant("Steotype");
            case 5:
                return QVariant("S");
            case 6:
                return QVariant("A");
            case 7:
                return QVariant("C");
            case 8:
                return QVariant("Doc");
            case 9:
                return QVariant("Source Code");
        }
    }
    return QVariant();
}