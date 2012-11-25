#include "packagegroup.h"

PackageGroup::PackageGroup(QWidget* parent) : PageGroupBase(parent),ui(new Ui_PackageTabGroup())
{
    ui->setupUi(this);
}

PackageGroup::~PackageGroup()
{
    delete ui;
}

void PackageGroup::setCurrentObject(UMLObject* o)
{
    ui->m_pAssociationsPage;
    ui->m_pGeneralPage;
    ui->m_pContentPage;
}