#include "enumgeneral.h"

#include <QtGui/QWidget>

EnumGeneral::EnumGeneral(QWidget* parent) : QWidget(parent),ui(new Ui_EnumGeneral())
{
    ui->setupUi(this);
}

EnumGeneral::~EnumGeneral()
{
    delete ui;
}