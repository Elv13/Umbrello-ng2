#ifndef DOCK_ENUM_LITERALS_MODEL_H
#define DOCK_ENUM_LITERALS_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class EnumLiteralsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       EnumLiteralsModel(QObject* parent = NULL);
       virtual ~EnumLiteralsModel();

    private:
        UMLClassifier* m_pData;

};

#endif
