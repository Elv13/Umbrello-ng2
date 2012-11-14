#include "classgeneral.h"

#include <QtGui/QWidget>

ClassGeneral::ClassGeneral(QWidget* parent) : QWidget(parent),ui(new Ui_ClassGeneral())
{
    ui->setupUi(this);
}

ClassGeneral::~ClassGeneral()
{
    delete ui;
}