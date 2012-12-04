#include "doctexteditor.h"

#include "texteditor/model/doccompletionmodel.h"

#include <KTextEditor/CodeCompletionModel>
#include <KTextEditor/CodeCompletionInterface>
#include <KTextEditor/HighlightInterface>
#include <KTextEditor/View>
#include <KTextEditor/Document>

#include <unistd.h>


DocTextEditor::DocTextEditor(QObject* parent) : TextEditorBase(parent) {
    KTextEditor::CodeCompletionInterface *iface = qobject_cast<KTextEditor::CodeCompletionInterface*>( m_view );

    if( iface ) {
        //iface->unregisterCompletionModel(KateGlobal::self()->wordCompletionModel()); //If you really think it's usefull, remove this line
        iface->registerCompletionModel(new DocumentationCompletion(m_view,"@"));
        iface->setAutomaticInvocationEnabled(true);
    }
    
    m_doc->setHighlightingMode("Doxygen");
}