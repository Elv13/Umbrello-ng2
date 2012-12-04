#ifndef DOCK_CLASS_ATTRIBUTES_MODEL_H
#define DOCK_CLASS_ATTRIBUTES_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;
class UMLObject;

class ClassAttributesModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
        ClassAttributesModel(QObject* parent = NULL);
        virtual ~ClassAttributesModel();

        virtual int         columnCount (const QModelIndex& parent = QModelIndex() ) const;
        virtual QVariant    data        (const QModelIndex& index, int role = Qt::DisplayRole ) const;
        virtual QModelIndex index       (int row, int column, const QModelIndex& parent = QModelIndex() ) const;
        virtual QModelIndex parent      (const QModelIndex& index ) const;
        virtual int         rowCount    (const QModelIndex& parent = QModelIndex() ) const;
        virtual bool        setData     (const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
        virtual QVariant    headerData  (int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
        virtual Qt::ItemFlags flags(const QModelIndex& index) const;

       void setCurrentObject(UMLObject* o);

    private:
        QVariant privData(const QModelIndex& index) const;
        enum AttributesColumn {
            Name =0,
            Type,
            InitialValue,
            Visibility,
            StereotypeName,
            Static,
            Documentation,
        };
        UMLClassifier* m_pData;

};

#endif
