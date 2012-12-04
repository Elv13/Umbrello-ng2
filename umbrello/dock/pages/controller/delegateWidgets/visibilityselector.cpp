#include "visibilityselector.h"

#include <QtGui/QHBoxLayout>
#include <KComboBox>

VisibilitySelector::VisibilitySelector(const QModelIndex& index, QWidget* parent) : DelegateWidgetBase(index,parent)
{
    m_combo = new KComboBox();
    QStringList values;
    values << "Public" << "Private" << "Protected" << "Implementation";
    m_combo->addItems(values);
    m_combo->setContentsMargins(0,0,0,0);
    QHBoxLayout* l = new QHBoxLayout(this);
    l->setSpacing(0);
    l->setContentsMargins(0,0,0,0);
    l->addWidget(m_combo);
}

VisibilitySelector::~VisibilitySelector()
{
    delete m_combo;
}

void VisibilitySelector::indexChanged()
{
    
}