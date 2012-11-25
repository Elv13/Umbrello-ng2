#include "classassoc.h"

#include "dock/pages/model/classassociationsmodel.h"

ClassAssoc::ClassAssoc(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

ClassAssoc::~ClassAssoc()
{
    delete ui;
}

void ClassAssoc::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new ClassAssociationsModel(this);
        ui->m_pTable->setModel(m_pModel);
    }
    m_pModel->setCurrentObject(o);
}