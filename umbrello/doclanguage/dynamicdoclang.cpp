#include "dynamicdoclang.h"

#include <QVector>
#include <QUrl>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <unistd.h>

#include <kglobal.h>
#include <kstandarddirs.h>

#include "argtype.h"
#include "docarg.h"
#include "doctagbloc.h"

struct TagArgEnum {
    static const char NAME[];
    static const char SHORT[];
    static const char DESCRIPTION[];
    static const char ARGS[];
    static const char TAG[];
    static const char ARG[];
};

//TODO merge with above once Umbrello require C++oX / C++2011
const char TagArgEnum::TAG[]          = "tag"        ;
const char TagArgEnum::NAME[]         = "name"       ;
const char TagArgEnum::SHORT[]        = "short"      ;
const char TagArgEnum::DESCRIPTION[]  = "description";
const char TagArgEnum::ARGS[]         = "args"       ;
const char TagArgEnum::ARG[]          = "arg"        ;


struct TopLevelEnum {
    static const char TAGS[];
    static const char LANGUAGE[];
};

const char TopLevelEnum::TAGS[]     = "tags"       ;
const char TopLevelEnum::LANGUAGE[] = "language"   ;

struct LangEnum {
    static const char ARGTYPE[];
    static const char PREFIXES[];
    static const char PREFIX[];
    static const char BLOCKS[];
    static const char BLOC[];
    static const char TYPE[];
};

const char LangEnum::ARGTYPE[]      = "argtype"    ;
const char LangEnum::PREFIXES[]     = "prefixes"   ;
const char LangEnum::PREFIX[]       = "prefix"     ;
const char LangEnum::BLOCKS[]       = "blocks"     ;
const char LangEnum::BLOC[]         = "bloc"       ;
const char LangEnum::TYPE[]         = "type"       ;

struct BlocEnum {
    static const char LANGUAGE[];
    static const char OPEN[];
    static const char CLOSE[];
};

const char BlocEnum::LANGUAGE[]     = "language"   ;
const char BlocEnum::OPEN[]         = "open"       ;
const char BlocEnum::CLOSE[]        = "close"      ;

QHash<QString,DynamicDocLang*> DynamicDocLang::m_pLoadedLanguages = QHash<QString,DynamicDocLang*>() ;
QHash<QString,QString>         DynamicDocLang::m_pLanguageList     = QHash<QString,QString>()         ;
bool                           DynamicDocLang::m_pListInit        = false                            ;

const QHash<QString,QString>& DynamicDocLang::getLanguageList()
{
    if (!m_pListInit) {
        //TODO make international
        QStringList langList = KGlobal::dirs()->findAllResources("data","umbrello/doclanguage/en_US/*.xml", KStandardDirs::NoDuplicates);
        foreach(QString lang, langList) {
            m_pLanguageList[lang.split("/")[lang.split("/").size()-1]] = lang;
        }
        m_pListInit = true;
    }
    return m_pLanguageList;
}

DynamicDocLang* DynamicDocLang::getLanguage(QString name)
{
    if (m_pLoadedLanguages[name] == 0) {
        if (!getLanguageList()[name].isEmpty()) {
            m_pLoadedLanguages[name] = new DynamicDocLang(QUrl(getLanguageList()[name]));
        }
    }
    
    return m_pLoadedLanguages[name];
}

DynamicDocLang::DynamicDocLang(const QUrl& path)
{
    QDomDocument doc("mydocument");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return ;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    QDomNode n = doc.documentElement().firstChild();
    while(!n.isNull()) {
        QDomNode n2 = n.firstChild();
        if (n.toElement().tagName().toLower() == TopLevelEnum::LANGUAGE) {
            while(!n2.isNull()) {
                QDomElement e = n2.toElement();
                if(!e.isNull()) {
                    if      (e.tagName().toLower() == LangEnum::ARGTYPE  ) {
                        QDomNode n3 = n2.firstChild();
                        while(!n3.isNull()) {
                            QDomElement e2 = n3.toElement();
                            if(!e2.isNull()) {
                                if      (e2.tagName().toLower() == LangEnum::TYPE   ) {
                                    if (e2.hasAttribute("name") && m_pArgType[e2.attribute("name")] == 0) {
                                        m_pArgType[e2.attribute("name")] = new ArgType(e2.attribute("name"),e2.text().trimmed());
                                    }
                                    else {
                                        //TODO
                                    }
                                }
                                else {
                                    //TODO
                                }
                            }
                            n3 = n3.nextSibling();
                        }
                    }
                    else if (e.tagName().toLower() == LangEnum::PREFIXES ) {
                        QDomNode n3 = n2.firstChild();
                        while(!n3.isNull()) {
                            QDomElement e2 = n3.toElement();
                            if(!e2.isNull()) {
                                if      (e2.tagName().toLower() == LangEnum::PREFIX ) {
                                    if (e2.hasAttribute(    BlocEnum::LANGUAGE ) 
                                        && e2.hasAttribute( BlocEnum::OPEN     )  
                                        && e2.hasAttribute( BlocEnum::CLOSE    )) {
                                        //TODO
                                    }
                                    else {
                                        //TODO
                                    }
                                }
                                else {
                                    //TODO
                                }
                            }
                            n3 = n3.nextSibling();
                        }
                    }
                    else if (e.tagName().toLower() == LangEnum::BLOCKS   ) {
                        QDomNode n3 = n2.firstChild();
                        while(!n3.isNull()) {
                            QDomElement e2 = n3.toElement();
                            if(!e2.isNull()) {
                                if      (e2.tagName().toLower() == LangEnum::BLOC   ) {
                                    //TODO
                                }
                                else {
                                    //TODO
                                }
                            }
                            n3 = n3.nextSibling();
                        }
                    }
                    else {
                        //TODO
                    }
                }
                n2 = n2.nextSibling();
            }
        }
        else if (n.toElement().tagName().toLower() == TopLevelEnum::TAGS) {
            while(!n2.isNull()) {
                QVector<DocArg*> args;
                QString name,shortDesc,description;
                QDomElement e = n2.toElement();
                if((!e.isNull()) && (e.tagName().toLower() == TagArgEnum::TAG)) {
                    QDomNode n3 = n2.firstChild();
                     while(!n3.isNull()) {
                        QDomElement e2 = n3.toElement();
                        if(!e2.isNull()) {
                            if      (e2.tagName().toLower() == TagArgEnum::NAME       ) {
                                name = e2.text().trimmed();
                            }
                            else if (e2.tagName().toLower() == TagArgEnum::ARGS       ) {
                                QDomNode n4 = n3.firstChild();
                                while(!n4.isNull()) {
                                    QDomElement e3 = n4.toElement();
                                    if((!e3.isNull()) && (e3.tagName().toLower() == TagArgEnum::ARG)) {
                                        //TODO
                                        if (e3.hasAttribute("type")) {
                                            args << new DocArg(e3.text().trimmed(),(uint)0,m_pArgType[e3.attribute("type")]);
                                        }
                                    }
                                    n4 = n4.nextSibling();
                                }
                            }
                            else if (e2.tagName().toLower() == TagArgEnum::SHORT      ) {
                                shortDesc = e2.text().trimmed();
                            }
                            else if (e2.tagName().toLower() == TagArgEnum::DESCRIPTION) {
                                description = e2.text().trimmed();
                            }
                            else {
                                //TODO
                            }
                        }
                        n3 = n3.nextSibling();
                     }
                }
                qDebug() << name;
                DocTagBloc* docTag = new DocTagBloc(name,description,shortDesc);
                docTag->setArgs(args);
                m_pTags << docTag;
                n2 = n2.nextSibling();
            }
        }
        //m_pDoxygenList << tag;
        n = n.nextSibling();
    }
    return;
}