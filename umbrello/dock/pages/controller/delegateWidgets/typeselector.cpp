#include "typeselector.h"

#include <QtGui/QHBoxLayout>
#include <QtGui/QComboBox>

TypeSelector::TypeSelector(const QModelIndex& index, QWidget* parent) : DelegateWidgetBase(index,parent)
{
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    m_combo = new QComboBox();
    m_combo->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    m_combo->setEditable(true);
    QStringList values;
    values << "int" << "float" << "double" << "bool";
    m_combo->addItems(values);
    m_combo->setContentsMargins(0,0,0,0);
    QHBoxLayout* l = new QHBoxLayout(this);
    l->setSpacing(0);
    l->setContentsMargins(0,0,0,0);
    l->addWidget(m_combo);
}

TypeSelector::~TypeSelector()
{
    delete m_combo;
}

void TypeSelector::indexChanged()
{
    
}