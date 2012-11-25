#include "enumliterals.h"

#include "dock/pages/model/enumliteralsmodel.h"

EnumLiterals::EnumLiterals(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

EnumLiterals::~EnumLiterals()
{
    delete ui;
}

void EnumLiterals::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new EnumLiteralsModel(this);
        ui->m_pTable->setModel(m_pModel);
    }
    m_pModel->setCurrentObject(o);
}