#ifndef COMMENT_BLOC_H
#define COMMENT_BLOC_H

#include <QVector>
#include "doctextblocbase.h"
#include "dynamicdoclang.h"

class CommentBloc {
public:
    CommentBloc();
    CommentBloc(QString text);
    void setText(const QString& text);
    const QString& text();
private:
    QVector<DocTextBlocBase*> m_pContent;
    bool m_pHasChanged;
    DynamicDocLang* m_pLang;
    QString m_text;
};

#endif