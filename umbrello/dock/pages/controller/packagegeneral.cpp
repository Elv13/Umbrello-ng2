#include "packagegeneral.h"

#include <QtGui/QWidget>
#include <KTextEditor/Document>
#include <KTextEditor/View>
#include "texteditor/controller/doctexteditor.h"

PackageGeneral::PackageGeneral(QWidget* parent) : PageBase(parent),ui(new Ui_PackageGeneral())
{
    ui->setupUi(this);
    m_pDoc = new DocTextEditor(this);
    ui->verticalLayout->addWidget(m_pDoc->widget());
}

PackageGeneral::~PackageGeneral()
{
    delete ui;
}

void PackageGeneral::setCurrentObject(UMLObject* o)
{
    
}