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

QVariant ClassOperationsModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case ClassOperationsModel::Name:
                    QVariant(m_pData->getOpList()[index.row()]->name());
                    break;
                case ClassOperationsModel::Parameters:
                    QVariant("TODO");
                    break;
                case ClassOperationsModel::Type:
                    QVariant(m_pData->getOpList()[index.row()]->getTypeName());
                    break;
                case ClassOperationsModel::Visibility:
                    QVariant(m_pData->getOpList()[index.row()]->visibility());
                    break;
                case ClassOperationsModel::Steotype:
                    return QVariant(m_pData->getOpList()[index.row()]->stereotype());
                    break;
                case ClassOperationsModel::Static:
                    return QVariant(m_pData->getOpList()[index.row()]->isStatic());
                    break;
                case ClassOperationsModel::Abstract:
                    return QVariant(m_pData->getOpList()[index.row()]->isAbstract());
                    break;
                case ClassOperationsModel::Constant:
                    return QVariant(m_pData->getOpList()[index.row()]->getConst());
                    break;
                case ClassOperationsModel::Documentation:
                    return QVariant(m_pData->getOpList()[index.row()]->doc());
                    break;
                case ClassOperationsModel::SourceCode:
                    QVariant("TODO");
                    break;
            }
            break;
    }

    return QVariant();
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