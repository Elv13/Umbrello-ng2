#include "docarg.h"

#include "argtype.h"

#include <QString>

DocArg::DocArg(const QString& name, const uint index, const ArgType* type) :
    m_pName(name), m_pIndex(index), m_pType(type)
{
    
}

DocArg::DocArg(const DocArg& baseArg) :
    m_pName(baseArg.m_pName), m_pIndex(baseArg.m_pIndex), m_pType(baseArg.m_pType)
{
    //Q_ASSERT(!baseArg.getValue().isEmpty());
}