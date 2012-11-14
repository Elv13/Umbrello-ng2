#include "classassoc.h"

ClassAssoc::ClassAssoc(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

ClassAssoc::~ClassAssoc()
{
    delete ui;
}