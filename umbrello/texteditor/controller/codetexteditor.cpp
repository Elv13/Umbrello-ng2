#include "codetexteditor.h"

#include "basictypes.h"
#include "uml.h"

#include <KTextEditor/CodeCompletionModel>
#include <KTextEditor/CodeCompletionInterface>
#include <KTextEditor/HighlightInterface>
#include <KTextEditor/View>
#include <KTextEditor/Document>

#include <unistd.h>


CodeTextEditor::CodeTextEditor(QObject* parent) : TextEditorBase(parent) {
    //KTextEditor::CodeCompletionInterface *iface = qobject_cast<KTextEditor::CodeCompletionInterface*>( m_view );
    //if( iface ) {
    //}
    
    //KTextEditor::HighlightInterface *ifaceHighlight = qobject_cast<KTextEditor::HighlightInterface*>( m_doc );

    //if( ifaceHighlight ) {
        // the implementation supports the interface
        // do stuff
    //}
    
    QString language = Uml::ProgrammingLanguage::toString(UMLApp::app()->activeLanguage());
    m_doc->setHighlightingMode(language);
}