#ifndef DOC_TEXT_BLOC_H
#define DOC_TEXT_BLOC_H

#include "doctextblocbase.h"

#include <QString>

class DocTextBloc : public DocTextBlocBase {
public:
    inline virtual const QString& text();
    void setText(const QString& text);
private:
    QString m_pText;
};

#endif