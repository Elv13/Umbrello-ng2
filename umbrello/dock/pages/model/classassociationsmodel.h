#ifndef DOCK_CLASS_ASSOC_MODEL_H
#define DOCK_CLASS_ASSOC_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class ClassAssociationsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       ClassAssociationsModel(QObject* parent = NULL);
       virtual ~ClassAssociationsModel();

    private:
        UMLClassifier* m_pData;

};

#endif
