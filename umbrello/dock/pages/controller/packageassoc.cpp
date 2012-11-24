#include "packageassoc.h"

#include "dock/pages/model/packageassociationsmodel.h"

PackageAssoc::PackageAssoc(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

PackageAssoc::~PackageAssoc()
{
    delete ui;
}

void PackageAssoc::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new PackageAssociationsModel(this);
    }
    m_pModel->setCurrentObject(o);
}