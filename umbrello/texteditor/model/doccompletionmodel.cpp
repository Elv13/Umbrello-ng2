#include "doccompletionmodel.h"

#include "doclanguage/dynamicdoclang.h"
#include "doclanguage/doctagbloc.h"

#include <QStringList>
#include <QFile>
#include <QUrl>

#include <KTextEditor/CodeCompletionModel>
#include <KTextEditor/CodeCompletionInterface>
#include <KTextEditor/View>
#include <KTextEditor/Document>

DynamicDocLang* DocumentationCompletion::m_pDocumentationModel = 0;

DocumentationCompletion::DocumentationCompletion(KTextEditor::View* parent, const QString &startText) : 
    KTextEditor::CodeCompletionModel(parent), m_pListInit(false), m_startText(startText), 
    m_autoStartText(m_startText.isEmpty())
{
    
    //Prefix, Icon, Scope, Name, Arguments, Postfix
    if (!m_pListInit) {
        foreach (DocTagBloc* aTag,getDoxygenList()) {
            QStringList t;
            t << "" << "" << "" << aTag->getName() << aTag->getArgsDescription() << aTag->getShortDesc() << aTag->getDescription();
            m_pCurrentList << t;
        }
        setRowCount(m_pCurrentList.size());
        m_pListInit = true;
    }
    
}

DocumentationCompletion::~DocumentationCompletion()
{
    
}

void DocumentationCompletion::completionInvoked(KTextEditor::View* view, const KTextEditor::Range &range, KTextEditor::CodeCompletionModel::InvocationType invocationType) 
{
    Q_UNUSED(invocationType)

//     if (m_autoStartText) {
//         m_startText = view->document()->text(KTextEditor::Range(range.start(), view->cursorPosition()));
//     }
    
}

QVariant DocumentationCompletion::data( const QModelIndex & index, int role ) const
{
  switch (role) {
    case Qt::DisplayRole:
      
      switch (index.column()) {
        case Prefix:
            return m_pCurrentList[index.row()][Prefix];

        case Scope:
            return m_pCurrentList[index.row()][Scope];

        case Name:
            return m_pCurrentList[index.row()][Name];

        case Arguments:
            return m_pCurrentList[index.row()][Arguments];
        case Postfix:
            return m_pCurrentList[index.row()][Postfix];
      }
        break;

    case Qt::DecorationRole:
      break;
      
    case Qt::ToolTipRole:
        return m_pCurrentList[index.row()][Postfix+1];
        break;

    case CompletionRole: {
      CompletionProperties p;
      if (index.row() < rowCount() / 2)
        p |= Function;
      else
        p |= Variable;
      switch (index.row() % 3) {
        case 0:
          p |= Const | Public;
          break;
        case 1:
          p |= Protected;
          break;
        case 2:
          p |= Private;
          break;
      }
      return (int)p;
    }

    case ScopeIndex:
      return (index.row() % 4 ) - 1;  
  }

  return QVariant();
}

const QVector<DocTagBloc*>& DocumentationCompletion::getDoxygenList()
{
    if (!m_pDocumentationModel) {
        m_pDocumentationModel = DynamicDocLang::getLanguage("doxygen.xml");
        if (!m_pDocumentationModel)
            return QVector<DocTagBloc*>();
    }
    return m_pDocumentationModel->getTags();
}