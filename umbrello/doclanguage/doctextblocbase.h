#ifndef DOC_TEXT_BLOC_BASE_H
#define DOC_TEXT_BLOC_BASE_H

class QString;

class DocTextBlocBase {
public:
    virtual const QString& text() = 0;
    virtual ~DocTextBlocBase();
};

#endif