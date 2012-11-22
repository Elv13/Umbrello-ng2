#ifndef DOCK_PACKAGE_ASSOC_MODEL_H
#define DOCK_PACKAGE_ASSOC_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class PackageAssociationsModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       PackageAssociationsModel(QObject* parent = NULL);
       virtual ~PackageAssociationsModel();

    private:
        UMLClassifier* m_pData;

};

#endif
