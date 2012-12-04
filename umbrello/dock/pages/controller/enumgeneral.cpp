#include "enumgeneral.h"

#include <QtGui/QWidget>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include "texteditor/controller/doctexteditor.h"

EnumGeneral::EnumGeneral(QWidget* parent) : PageBase(parent),ui(new Ui_EnumGeneral())
{
    ui->setupUi(this);
    m_pDoc = new DocTextEditor(this);
    ui->verticalLayout->addWidget(m_pDoc->widget());
}

EnumGeneral::~EnumGeneral()
{
    delete ui;
}

void EnumGeneral::setCurrentObject(UMLObject* o)
{
    
}