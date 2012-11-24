#include "classtemplates.h"

#include "dock/pages/model/classtemplatesmodel.h"

ClassTemplates::ClassTemplates(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

ClassTemplates::~ClassTemplates()
{
    delete ui;
}

void ClassTemplates::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new ClassTemplatesModel(this);
    }
    m_pModel->setCurrentObject(o);
}