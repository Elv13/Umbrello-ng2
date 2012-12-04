#ifndef DOCCOMPLETIONMODEL_H
#define DOCCOMPLETIONMODEL_H

#include <ktexteditor/codecompletionmodel.h>

namespace KTextEditor {
  class View;
  class CodeCompletionInterface;
}

class QStringList;
class DocTagBloc;
class DynamicDocLang;

class DocumentationCompletion : public KTextEditor::CodeCompletionModel {
    Q_OBJECT
public:
    DocumentationCompletion(KTextEditor::View* parent, const QString &startText);
    virtual ~DocumentationCompletion();
    virtual void completionInvoked(KTextEditor::View* view, const KTextEditor::Range& range, InvocationType invocationType);
    //virtual QMap<int, QVariant> itemData(const QModelIndex &index) const;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
private:
    bool m_pListInit;
    QString m_startText;
    bool m_autoStartText;
    QList<QStringList> m_pCurrentList;
    static DynamicDocLang* m_pDocumentationModel;
    
    static const QVector<DocTagBloc*>& getDoxygenList();
};

#endif