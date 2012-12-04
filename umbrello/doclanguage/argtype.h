#ifndef ARG_TYPE_H
#define ARG_TYPE_H

#include <QString>
class QString;

class ArgType {
public:
    //Only DynamicDocLang can create new ArgTypes
    friend class DynamicDocLang;
    
    //Getters
    inline const QString& getName()  { return m_pName;  }
    inline const QString& getRegex() { return m_pRegex; }
    
    //Setters
    
private:
    //Private constrctors
    explicit ArgType(const QString& name, const QString& regex);
    
    //Members
    const QString m_pRegex;
    const QString m_pName;
};

#endif