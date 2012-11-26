#ifndef DOCK_PACKAGE_ASSOC_MODEL_H
#define DOCK_PACKAGE_ASSOC_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLPackage;
class UMLObject;

class PackageAssociationsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       PackageAssociationsModel(QObject* parent = NULL);
       virtual ~PackageAssociationsModel();

       int         columnCount(const QModelIndex& parent = QModelIndex() ) const;
       QVariant    data(const QModelIndex& index, int role = Qt::DisplayRole ) const;
       QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex() ) const;
       QModelIndex parent(const QModelIndex& index ) const;
       int         rowCount(const QModelIndex& parent = QModelIndex() ) const;
       bool        setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
       virtual QVariant    headerData  (int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

       void setCurrentObject(UMLObject* o);

    private:
        enum PackageAssociationsColumns {
            Name =0,
            Direction,
            Buddy,
            Type,
            Doc
        };
        UMLPackage* m_pData;

};

#endif
