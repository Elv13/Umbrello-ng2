#include "argtype.h"

#include <QString>

ArgType::ArgType(const QString& name, const QString& regex) :
    m_pName(name), m_pRegex(regex)
{
    
}