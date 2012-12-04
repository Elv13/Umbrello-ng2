#ifndef DOC_TEXT_EDITOR_H
#define DOC_TEXT_EDITOR_H

#include "texteditorbase.h"

class DocTextEditor : public TextEditorBase
{
    Q_OBJECT
public: 
    DocTextEditor(QObject* parent);
};

#endif