#include "classattributes.h"

#include "dock/pages/model/classattributesmodel.h"
#include <QtCore/QDebug>

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
        ui->m_pTable->setModel(m_pModel);
        ui->m_pTable->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        for (int i=1;i<m_pModel->columnCount();i++) {
            ui->m_pTable->horizontalHeader()->setResizeMode(i,QHeaderView::ResizeToContents);
        }
    }
    m_pModel->setCurrentObject(o);
}