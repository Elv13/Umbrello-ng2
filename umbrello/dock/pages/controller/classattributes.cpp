#include "classattributes.h"

#include "dock/pages/model/classattributesmodel.h"
#include <QtCore/QDebug>
#include <QtGui/QPushButton>
#include "delegateWidgets/docbutton.h"
#include "delegateWidgets/visibilityselector.h"
#include "delegateWidgets/typeselector.h"

ClassAttributes::ClassAttributes(QWidget* parent) : PageBase(parent),ui(new Ui_GenericTable()),m_pModel(0)
{
    ui->setupUi(this);
}

ClassAttributes::~ClassAttributes()
{
    delete ui;
}

void ClassAttributes::setCurrentObject(UMLObject* o)
{
    if (!m_pModel) {
        m_pModel = new ClassAttributesModel(this);
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
void ClassAttributes::rowsInserted ()
{
    for (int i=0;i<m_pModel->rowCount()-1;i++) {
        QModelIndex index = m_pModel->index(i,ClassAttributesModel::Documentation);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new DocButton(index,ui->m_pTable));
        }
        index = m_pModel->index(i,ClassAttributesModel::Visibility);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new VisibilitySelector(index,ui->m_pTable));
        }
        index = m_pModel->index(i,ClassAttributesModel::Type);
        if (!ui->m_pTable->indexWidget(index)) {
            ui->m_pTable->setIndexWidget(index,new TypeSelector(index,ui->m_pTable));
        }
    }
}

void ClassAttributes::addRow()
{
//     ui->m_pTable->selectRow(m_pModel->rowCount()-1);
    ui->m_pTable->setFocus(Qt::OtherFocusReason);
    ui->m_pTable->selectionModel()->setCurrentIndex(m_pModel->index(m_pModel->rowCount()-1,0),QItemSelectionModel::Select|QItemSelectionModel::Current);
}