#ifndef DOCK_CLASS_OPERATIONS_MODEL_H
#define DOCK_CLASS_OPERATIONS_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class ClassOperationsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       ClassOperationsModel(QObject* parent = NULL);
       virtual ~ClassOperationsModel();

    private:
        UMLClassifier* m_pData;

};

#endif
