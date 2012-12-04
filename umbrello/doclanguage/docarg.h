#ifndef DOC_ARG_H
#define DOC_ARG_H

#include <QString>

class QString;
class ArgType;

class DocArg {
public:
    //Only DynamicDocLang can create new kind of DocArg
    friend class DynamicDocLang;
    
    //Public Constructor
    DocArg(const DocArg& baseArg);
    
    //Getters
    inline const QString& getName()  { return m_pName;  }
    inline const uint     getIndex() { return m_pIndex; }
    inline const ArgType* getType()  { return m_pType;  }
    inline       QString  getValue() { return m_pValue; }
    
    //Setters
    inline void setValue(const QString value) { m_pValue = value; }
    
private:
    //Private Constructor
    explicit DocArg(const QString& name, const uint index, const ArgType* type);
    
    //Members
    const QString  m_pName;
    const uint     m_pIndex;
    QString        m_pValue;
    const ArgType* m_pType;
};

#endif