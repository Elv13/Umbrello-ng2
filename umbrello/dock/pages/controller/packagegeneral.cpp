#include "packagegeneral.h"

#include <QtGui/QWidget>

PackageGeneral::PackageGeneral(QWidget* parent) : PageBase(parent),ui(new Ui_PackageGeneral())
{
    ui->setupUi(this);
}

PackageGeneral::~PackageGeneral()
{
    delete ui;
}

void PackageGeneral::setCurrentObject(UMLObject* o)
{
    
}