#include "classoperations.h"

ClassOperations::ClassOperations(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

ClassOperations::~ClassOperations()
{
    delete ui;
}