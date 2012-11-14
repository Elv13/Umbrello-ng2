#include "classattributes.h"

ClassAttributes::ClassAttributes(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

ClassAttributes::~ClassAttributes()
{
    delete ui;
}