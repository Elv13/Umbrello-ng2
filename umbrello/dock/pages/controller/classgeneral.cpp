#include "classgeneral.h"

#include <QtGui/QWidget>

ClassGeneral::ClassGeneral(QWidget* parent) : PageBase(parent),ui(new Ui_ClassGeneral())
{
    ui->setupUi(this);
}

ClassGeneral::~ClassGeneral()
{
    delete ui;
}

void ClassGeneral::setCurrentObject(UMLObject* o)
{
    
}