#include "packagegeneral.h"

#include <QtGui/QWidget>

PackageGeneral::PackageGeneral(QWidget* parent) : QWidget(parent),ui(new Ui_PackageGeneral())
{
    ui->setupUi(this);
}

PackageGeneral::~PackageGeneral()
{
    delete ui;
}