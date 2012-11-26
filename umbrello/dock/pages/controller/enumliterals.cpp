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
        ui->m_pTable->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        for (int i=1;i<m_pModel->columnCount();i++) {
            ui->m_pTable->horizontalHeader()->setResizeMode(i,QHeaderView::ResizeToContents);
        }
    }
    m_pModel->setCurrentObject(o);
}