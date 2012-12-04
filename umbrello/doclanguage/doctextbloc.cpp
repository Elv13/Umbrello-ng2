#include "doctextbloc.h"

#include <QString>

const QString& DocTextBloc::text()
{
    return m_pText;
}

void DocTextBloc::setText(const QString& text) 
{ 
    m_pText = text; 
    
}