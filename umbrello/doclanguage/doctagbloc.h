#ifndef DOC_TAG_H
#define DOC_TAG_H

#include "doctextblocbase.h"

#include <QVector>
#include <QString>

class QString;

class DocArg;

class DocTagBloc : public DocTextBlocBase {
public:
    //Only DynamicDocLang can create new kind of Tags
    friend class DynamicDocLang;
    
    //Public constructor
    DocTagBloc(const DocTagBloc& other);
    
    //Getters
    inline const QString& getName()            { return m_pName;        }
    inline const QString& getShortDesc()       { return m_pShortDesc;   }
    inline const QString& getDescription()     { return m_pDescription; }
    QString getArgsDescription();
    virtual const QString& text();
    
    //Mutators
    bool parse(QString content);
    
    //TODO iterator
private:
    //Private constructor
    explicit DocTagBloc(const QString& name, const QString& description, const QString& shortDesc);
    inline void setArgs(QVector<DocArg*> args) { m_pArgs = args; }
    
    //Members
    const QString    m_pName;
    const QString    m_pDescription;
    const QString    m_pShortDesc;
    QVector<DocArg*> m_pArgs;
    QString          m_pBufferedText;
    bool             m_pHasChanged;
};

#endif