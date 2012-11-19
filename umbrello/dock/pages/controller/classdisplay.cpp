#include "classdisplay.h"

#include <QtGui/QWidget>

ClassDisplay::ClassDisplay(QWidget* parent) : QWidget(parent),ui(new Ui_ClassDisplay())
{
    ui->setupUi(this);
    ui->m_pColorPickerR->setChooserMode(ChooserRed);
    ui->m_pColorPickerG->setChooserMode(ChooserGreen);
    ui->m_pColorPickerB->setChooserMode(ChooserBlue);
}

ClassDisplay::~ClassDisplay()
{
    delete ui;
}