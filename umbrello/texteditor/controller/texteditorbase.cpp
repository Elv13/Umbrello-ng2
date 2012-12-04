#include "texteditorbase.h"

#include <KTextEditor/Document>
#include <KTextEditor/View>
#include <KTextEditor/Editor>
#include <KTextEditor/EditorChooser> 
#include <ktexteditor/configinterface.h>

TextEditorBase::TextEditorBase(QObject* parent) : QObject(parent) {
    KTextEditor::Editor *editor = KTextEditor::EditorChooser::editor();
    m_doc = editor->createDocument(0);
    m_view = qobject_cast<KTextEditor::View*>(m_doc->createView(0));
    KTextEditor::ConfigInterface *iface = qobject_cast<KTextEditor::ConfigInterface*>( m_view );
    if( iface ) {
        iface->setConfigValue("dynamic-word-wrap", true);
        iface->setConfigValue("line-numbers", true);
    }
}

KTextEditor::ConfigPage* TextEditorBase::getConfigPage() {
    //TODO
    return NULL;
}

KTextEditor::View* TextEditorBase::widget() {
    return m_view;
}

KTextEditor::Document* TextEditorBase::doc() {
    return m_doc;
}
