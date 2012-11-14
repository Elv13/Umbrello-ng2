#include "packagecontent.h"

PackageContent::PackageContent(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

PackageContent::~PackageContent()
{
    delete ui;
}