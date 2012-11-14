#include "classtemplates.h"

ClassTemplates::ClassTemplates(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

ClassTemplates::~ClassTemplates()
{
    delete ui;
}