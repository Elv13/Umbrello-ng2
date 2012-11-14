#include "enumliterals.h"

EnumLiterals::EnumLiterals(QWidget* parent) : QWidget(parent),ui(new Ui_GenericTable())
{
    ui->setupUi(this);
}

EnumLiterals::~EnumLiterals()
{
    delete ui;
}