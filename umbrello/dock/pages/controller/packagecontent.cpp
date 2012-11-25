#include "packagecontent.h"

#include "dock/pages/model/packagecontentmodel.h"

PackageContent::PackageContent(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

PackageContent::~PackageContent()
{
    delete ui;
}

void PackageContent::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new PackageContentModel(this);
        ui->m_pTable->setModel(m_pModel);
    }
    m_pModel->setCurrentObject(o);
}