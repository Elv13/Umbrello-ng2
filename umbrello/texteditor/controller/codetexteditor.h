#ifndef CODE_TEXT_EDITOR_H
#define CODE_TEXT_EDITOR_H

#include "texteditorbase.h"

class CodeTextEditor : public TextEditorBase
{
    Q_OBJECT
public: 
    CodeTextEditor(QObject* parent);
};

#endif