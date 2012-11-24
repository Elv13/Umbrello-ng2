#ifndef DOCK_CLASS_ASSOC_MODEL_H
#define DOCK_CLASS_ASSOC_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;
class UMLObject;

class ClassAssociationsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       ClassAssociationsModel(QObject* parent = NULL);
       virtual ~ClassAssociationsModel();

       int         columnCount(const QModelIndex& parent = QModelIndex() ) const;
       QVariant    data(const QModelIndex& index, int role = Qt::DisplayRole ) const;
       QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex() ) const;
       QModelIndex parent(const QModelIndex& index ) const;
       int         rowCount(const QModelIndex& parent = QModelIndex() ) const;
       bool        setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );

       void setCurrentObject(UMLObject* o);

    private:
        UMLClassifier* m_pData;

};

#endif
