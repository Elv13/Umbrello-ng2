#ifndef PAGE_GROUP_H
#define PAGE_GROUP_H

#include <QtCore/QObject>

class DockPage;

class PageGroup : public QObject
{
    Q_OBJECT
public:
    PageGroup(QObject* parent = NULL);
    virtual ~PageGroup();

    //Getters
    virtual const int& getIdentifier();

    //Mutator
    void addPage(DockPage* page);
protected:
    int m_Identifier;
};

#endif