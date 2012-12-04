#ifndef TEXT_EDITOR_BASE_H
#define TEXT_EDITOR_BASE_H

#include <QObject>
#include <kparts/mainwindow.h> 

namespace KTextEditor {
    class Document;
    class View;
    class Editor;
    class EditorChooser;
    class ConfigPage;
} 

/**
 * This class provide a common base for the documentation and code editor/viewer.
 * It is not a widget in itself, use the widget() method to get it. This have been
 * done to make it easier to maintain as this code is being used in many places
 */
class TextEditorBase : public QObject {
    Q_OBJECT
    
public:
    TextEditorBase(QObject* parent);
    static KTextEditor::ConfigPage* getConfigPage();
    KTextEditor::View* widget();
    KTextEditor::Document* doc();
protected:
    KTextEditor::View *m_view;
    KTextEditor::Document *m_doc;
    
};

#endif