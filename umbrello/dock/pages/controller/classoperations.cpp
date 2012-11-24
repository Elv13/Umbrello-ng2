#include "classoperations.h"

#include "dock/pages/model/classoperationsmodel.h"

ClassOperations::ClassOperations(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

ClassOperations::~ClassOperations()
{
    delete ui;
}

void ClassOperations::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new ClassOperationsModel(this);
    }
    m_pModel->setCurrentObject(o);
}