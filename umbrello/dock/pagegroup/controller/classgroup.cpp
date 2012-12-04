#include "classgroup.h"
#include <QtCore/QDebug>

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
    ui->m_pGeneralPage->setCurrentObject(o);
    ui->m_pAttributesPage->setCurrentObject(o);
    ui->m_pOperationsPage->setCurrentObject(o);
    ui->m_pTemplatesPage->setCurrentObject(o);
    ui->m_pAssociationsPage->setCurrentObject(o);
//     ui->m_pDisplayPage->setCurrentObject(0);
}

void ClassGroup::focusName()
{
    ui->m_pTabW->setCurrentIndex(0);
    ui->m_pGeneralPage->ui->m_pClassNameLE->setFocus(Qt::OtherFocusReason);
    ui->m_pGeneralPage->ui->m_pClassNameLE->selectAll();
}

PageBase* ClassGroup::currentPage()
{
    if (ui->m_pTabW->currentIndex() ==1)
        return ui->m_pAttributesPage;
    else if (ui->m_pTabW->currentIndex() ==2)
        return ui->m_pAttributesPage;
    return 0;
}