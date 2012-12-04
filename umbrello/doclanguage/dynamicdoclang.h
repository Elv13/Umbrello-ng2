#ifndef DYNAMIC_DOC_LANG_H
#define DYNAMIC_DOC_LANG_H

#include <QVector>
#include <QHash>

class QUrl;

class ArgType;
class DocArg;
class DocTagBloc;

typedef QHash<QString,QString> QStringHash;

class DynamicDocLang {
public:
    //Getters
    const DocTagBloc*                   getTag(const QString& name)   ;
    inline const  QVector<DocTagBloc*>& getTags() { return m_pTags; } ;
    static const QStringHash&       getLanguageList()             ;
    static DynamicDocLang*          getLanguage(QString name)     ;
    
    //Methods
    QVector<DocTagBloc> parse(const QString& content, bool& isValid = *(new bool(true)) );
private:
    //Private constructor
    DynamicDocLang(const QUrl& path);
    
    //Members
    QVector<DocTagBloc*>                      m_pTags             ;
    QHash<QString,ArgType*>               m_pArgType          ;
    static QHash<QString,DynamicDocLang*> m_pLoadedLanguages  ;
    static QHash<QString,QString>         m_pLanguageList     ;
    static bool                           m_pListInit         ;
};

#endif