#include "sourcebutton.h"

SourceButton::SourceButton(const QModelIndex& index, QWidget* parent) : TintedButtonBase(index,parent)
{
    setText("Source");
}

SourceButton::~SourceButton()
{
    
}

void SourceButton::indexChanged()
{
    
}