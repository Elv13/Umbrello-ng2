#include "packageassoc.h"

PackageAssoc::PackageAssoc(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

PackageAssoc::~PackageAssoc()
{
    delete ui;
}