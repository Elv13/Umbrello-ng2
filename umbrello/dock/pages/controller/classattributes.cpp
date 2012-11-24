#include "classattributes.h"

#include "dock/pages/model/classattributesmodel.h"

ClassAttributes::ClassAttributes(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

ClassAttributes::~ClassAttributes()
{
    delete ui;
}

void ClassAttributes::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new ClassAttributesModel(this);
    }
    m_pModel->setCurrentObject(o);
}