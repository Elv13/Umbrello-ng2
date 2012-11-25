#include "classgroup.h"

ClassGroup::ClassGroup(QWidget* parent) : PageGroupBase(parent),ui(new Ui_ClassTabGroup())
{
    ui->setupUi(this);
}

ClassGroup::~ClassGroup()
{
    delete ui;
}

void ClassGroup::setCurrentObject(UMLObject* o)
{
//     ui->m_pGeneralPage->setCurrentObject(0);
    ui->m_pAttributesPage->setCurrentObject(0);
    ui->m_pOperationsPage->setCurrentObject(0);
    ui->m_pTemplatesPage->setCurrentObject(0);
    ui->m_pAssociationsPage->setCurrentObject(0);
//     ui->m_pDisplayPage->setCurrentObject(0);
}