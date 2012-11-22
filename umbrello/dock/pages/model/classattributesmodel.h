#ifndef DOCK_CLASS_ATTRIBUTES_MODEL_H
#define DOCK_CLASS_ATTRIBUTES_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class ClassAttributesModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       ClassAttributesModel(QObject* parent = NULL);
       virtual ~ClassAttributesModel();

    private:
        UMLClassifier* m_pData;

};

#endif
