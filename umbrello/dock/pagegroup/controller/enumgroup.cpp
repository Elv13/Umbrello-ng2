#include "enumgroup.h"

EnumGroup::EnumGroup(QWidget* parent) : QWidget(parent),ui(new Ui_EnumTabGroup())
{
    ui->setupUi(this);
}

EnumGroup::~EnumGroup()
{
    delete ui;
}