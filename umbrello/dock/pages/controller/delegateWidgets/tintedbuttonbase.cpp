#include "tintedbuttonbase.h"

#include <QtGui/QPushButton>
#include <QtGui/QHBoxLayout>

TintedButtonBase::TintedButtonBase(const QModelIndex& index, QWidget* parent) : DelegateWidgetBase(index,parent)
{
    m_button = new QPushButton();
    m_button->setContentsMargins(0,0,0,0);
    QHBoxLayout* l = new QHBoxLayout(this);
    l->setSpacing(0);
    l->setContentsMargins(0,0,0,0);
    l->addWidget(m_button);
}

TintedButtonBase::~TintedButtonBase()
{
    delete m_button;
}

void TintedButtonBase::setText(const QString& text)
{
    m_button->setText(text);
}