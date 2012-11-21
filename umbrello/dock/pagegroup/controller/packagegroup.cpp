#include "packagegroup.h"

PackageGroup::PackageGroup(QWidget* parent) : PageGroupBase(parent),ui(new Ui_PackageTabGroup())
{
    ui->setupUi(this);
}

PackageGroup::~PackageGroup()
{
    delete ui;
}