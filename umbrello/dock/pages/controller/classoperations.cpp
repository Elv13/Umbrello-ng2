#include "classoperations.h"

#include "dock/pages/model/classoperationsmodel.h"
#include "delegateWidgets/docbutton.h"
#include "delegateWidgets/sourcebutton.h"
#include "delegateWidgets/visibilityselector.h"
#include "delegateWidgets/typeselector.h"
#include "delegateWidgets/paramwidget.h"

ClassOperations::ClassOperations(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

ClassOperations::~ClassOperations()
{
    delete ui;
}

void ClassOperations::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new ClassOperationsModel(this);
        ui->m_pTable->setModel(m_pModel);
        ui->m_pTable->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
        for (int i=1;i<m_pModel->columnCount();i++) {
            ui->m_pTable->horizontalHeader()->setResizeMode(i,QHeaderView::ResizeToContents);
        }
        connect(m_pModel,SIGNAL(layoutChanged()),this,SLOT(rowsInserted()));
    }
    m_pModel->setCurrentObject(o);
}

/**
 * Add indexWidgets if they don't already exist
 */
void ClassOperations::rowsInserted ()
{
    for (int i=0;i<m_pModel->rowCount();i++) {
        QModelIndex index = m_pModel->index(i,ClassOperationsModel::Documentation);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new DocButton(index,ui->m_pTable));
        }
        index = m_pModel->index(i,ClassOperationsModel::SourceCode);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new SourceButton(index,ui->m_pTable));
        }
        index = m_pModel->index(i,ClassOperationsModel::Visibility);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new VisibilitySelector(index,ui->m_pTable));
        }
        index = m_pModel->index(i,ClassOperationsModel::Type);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new TypeSelector(index,ui->m_pTable));
        }
        index = m_pModel->index(i,ClassOperationsModel::Parameters);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new ParamWidget(index,ui->m_pTable));
        }
        
    }
}