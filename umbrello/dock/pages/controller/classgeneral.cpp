#include "classgeneral.h"

#include <QtGui/QWidget>
#include "umlobject.h"

ClassGeneral::ClassGeneral(QWidget* parent) : PageBase(parent),ui(new Ui_ClassGeneral()),m_object(0)
{
    ui->setupUi(this);
    connect(ui->m_pClassNameLE,SIGNAL(textChanged(QString)),this,SLOT(slotNameChanged(QString)));
    connect(ui->m_pPackageLE,SIGNAL(textChanged(QString)),this,SLOT(slotPackageChanged(QString)));
//     connect(ui->,SIGNAL(),,SLOT());
    connect(ui->m_pStereotypeCBB->lineEdit(),SIGNAL(textChanged(QString)),this,SLOT(slotStereotypeChanged(QString)));
    connect(ui->m_pAbstractCK,SIGNAL(toggled(bool)),this,SLOT(slotAbstractChanged(bool)));
}

ClassGeneral::~ClassGeneral()
{
    delete ui;
}

void ClassGeneral::setCurrentObject(UMLObject* o)
{
    m_object = o;
    ui->m_pClassNameLE->setText(o->name());
    ui->m_pPackageLE->setText(o->package());
//     ui->m_pVisibilityCBB->setValue(o->visibility());
    ui->m_pStereotypeCBB->lineEdit()->setText(o->stereotype());
    ui->m_pAbstractCK->setChecked(o->isAbstract());
}

void ClassGeneral::slotNameChanged(QString name)
{
    if (m_object)
        m_object->setName(name);
}

void ClassGeneral::slotStereotypeChanged(QString stereotype)
{
    if (m_object)
        m_object->setStereotype(stereotype);
}

void ClassGeneral::slotAbstractChanged(bool abstract)
{
    if (m_object)
        m_object->setAbstract(abstract);
}

void ClassGeneral::slotPackageChanged(QString package)
{
    if (m_object)
        m_object->setPackage(package);
}

void ClassGeneral::slotVisibilityChanged(int index)
{
//     if (m_object)
//         m_object->setAbstract(name);
}
