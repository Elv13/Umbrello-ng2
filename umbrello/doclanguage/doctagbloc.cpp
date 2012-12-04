#include "doctagbloc.h"

#include "docarg.h"

#include <QString>

DocTagBloc::DocTagBloc(const DocTagBloc& other) :
    m_pName(other.m_pName), m_pDescription(other.m_pDescription), m_pShortDesc(other.m_pShortDesc),
    m_pHasChanged(true)
{
    
}

DocTagBloc::DocTagBloc(const QString& name, const QString& description, const QString& shortDesc) :
    m_pName(name), m_pDescription(description), m_pShortDesc(shortDesc), m_pHasChanged(true)
{
    
}

bool DocTagBloc::parse(QString content)
{
    return false;
}

QString DocTagBloc::getArgsDescription()
{
    QString toReturn;
    foreach (DocArg* arg, m_pArgs) {
        toReturn += " " + arg->getName();
    }
    return toReturn;
}

const QString& DocTagBloc::text()
{
    if (m_pHasChanged) {
        m_pBufferedText = m_pName;
        foreach (DocArg* arg, m_pArgs) {
            m_pBufferedText += " " + arg->getValue(); //TODO Add proper delimited support
        }
        
        m_pHasChanged = false;
    }
    return m_pBufferedText;
}