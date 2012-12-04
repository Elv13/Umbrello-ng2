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
    ui->m_pAssociationsPage->setCurrentObject(o);
    ui->m_pGeneralPage->setCurrentObject(o);
    ui->m_pContentPage->setCurrentObject(o);
}

void PackageGroup::focusName()
{
    ui->m_pTabW->setCurrentIndex(0);
    ui->m_pGeneralPage->ui->m_pClassNameLE->setFocus(Qt::OtherFocusReason);
    ui->m_pGeneralPage->ui->m_pClassNameLE->selectAll();
}