#ifndef DOCK_PAGES_H
#define DOCK_PAGES_H

#include <QtCore/QObject>

class QWidget;

class DockPage : public QObject
{
   Q_OBJECT
   public:
       DockPage(QWidget* parent = NULL);
       virtual ~DockPage();

       //Getters
       virtual QWidget* mainWidget() = 0;
   protected:
       QString m_PageName;
       QString m_PageDescription;

};

#endif
