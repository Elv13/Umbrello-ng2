#ifndef DOCK_CLASS_TEMPLATES_MODEL_H
#define DOCK_CLASS_TEMPLATES_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class ClassTemplatesModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       ClassTemplatesModel(QObject* parent = NULL);
       virtual ~ClassTemplatesModel();

    private:
        UMLClassifier* m_pData;

};

#endif
