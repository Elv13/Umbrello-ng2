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
    
}