#include "projectdock.h"
#include <QtGui/QWidget>
#include "projectdockmodel.h"

ProjectDock::ProjectDock(QWidget* parent):QDockWidget(parent),ui(new Ui_ProjectDock())
{
    ui->setupUi(this);
    ProjectDockModel* model = new ProjectDockModel(this);
    ui->m_pView->setModel(model);
}

ProjectDock::~ProjectDock()
{
    
}