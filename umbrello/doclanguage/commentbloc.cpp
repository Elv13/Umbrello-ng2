#include "commentbloc.h"

#include <QString>

CommentBloc::CommentBloc()
{
    
}

CommentBloc::CommentBloc(QString text)
{

}

const QString& CommentBloc::text()
{
    return m_text;
}

void CommentBloc::setText(const QString& text)
{
    m_text = text;
}