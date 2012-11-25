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
//     ui->m_GeneralPage;
    ui->m_pLiteralsPage;
}