#ifndef DOCK_PACKAGE_CONTENT_MODEL_H
#define DOCK_PACKAGE_CONTENT_MODEL_H

#include "ui_classGeneral.h"

#include <QtCore/QAbstractTableModel>

class UMLClassifier;

class PackageContentModel : public QAbstractTableModel
{
   Q_OBJECT
   public:
       PackageContentModel(QObject* parent = NULL);
       virtual ~PackageContentModel();

    private:
        UMLClassifier* m_pData;

};

#endif
