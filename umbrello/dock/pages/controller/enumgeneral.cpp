#include "enumgeneral.h"

#include <QtGui/QWidget>

EnumGeneral::EnumGeneral(QWidget* parent) : PageBase(parent),ui(new Ui_EnumGeneral())
{
    ui->setupUi(this);
}

EnumGeneral::~EnumGeneral()
{
    delete ui;
}

void EnumGeneral::setCurrentObject(UMLObject* o)
{
    
}