#ifndef PROJECT_DOCK_MODEL_H
#define PROJECT_DOCK_MODEL_H

#include <QtCore/QAbstractItemModel>

class ProjectDockModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ProjectDockModel(QObject* parent);
    virtual ~ProjectDockModel();
    
    int         columnCount(const QModelIndex& parent = QModelIndex() ) const;
    QVariant    data(const QModelIndex& index, int role = Qt::DisplayRole ) const;
    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex() ) const;
    QModelIndex parent(const QModelIndex& index ) const;
    int         rowCount(const QModelIndex& parent = QModelIndex() ) const;
    bool        setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
    virtual QVariant    headerData  (int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

private slots:
    void slotDiagramListChanged();
};

#endif