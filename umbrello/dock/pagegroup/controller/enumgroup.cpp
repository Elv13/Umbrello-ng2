#include "enumgroup.h"

EnumGroup::EnumGroup(QWidget* parent) : PageGroupBase(parent),ui(new Ui_EnumTabGroup())
{
    ui->setupUi(this);
}

EnumGroup::~EnumGroup()
{
    delete ui;
}

void EnumGroup::setCurrentObject(UMLObject* o)
{
//     ui->m_GeneralPage->setCurrentObject(o);
    ui->m_pLiteralsPage->setCurrentObject(o);
}

void EnumGroup::focusName()
{
    ui->m_pTabW->setCurrentIndex(0);
    ui->m_pGeneralPage->ui->m_pClassNameLE->setFocus(Qt::OtherFocusReason);
    ui->m_pGeneralPage->ui->m_pClassNameLE->selectAll();
}