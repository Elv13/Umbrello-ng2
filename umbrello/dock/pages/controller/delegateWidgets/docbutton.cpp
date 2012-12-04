#include "docbutton.h"

DocButton::DocButton(const QModelIndex& index, QWidget* parent) : TintedButtonBase(index,parent)
{
    setText("Doc");
}

DocButton::~DocButton()
{
    
}

void DocButton::indexChanged()
{
    
}