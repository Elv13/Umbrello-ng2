#ifndef DOCK_CLASS_OPERATIONS_MODEL_H
#define DOCK_CLASS_OPERATIONS_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;
class UMLObject;

class ClassOperationsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
        enum OperationsColumns {
            Name=0,
            Parameters,
            Type,
            Visibility,
            Steotype,
            Static,
            Abstract,
            Constant,
            Documentation,
            SourceCode,
        };
       ClassOperationsModel(QObject* parent = NULL);
       virtual ~ClassOperationsModel();

       virtual int         columnCount(const QModelIndex& parent = QModelIndex() ) const;
       virtual QVariant    data(const QModelIndex& index, int role = Qt::DisplayRole ) const;
       virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex() ) const;
       virtual QModelIndex parent(const QModelIndex& index ) const;
       virtual int         rowCount(const QModelIndex& parent = QModelIndex() ) const;
       virtual bool        setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
       virtual QVariant    headerData  (int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
       virtual Qt::ItemFlags flags(const QModelIndex& index) const;

       void setCurrentObject(UMLObject* o);

    private:
        QVariant privData(const QModelIndex& index) const;


        UMLClassifier* m_pData;

};

#endif
