/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2003-2011                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

// own header
#include "codegenselectpage.h"

//qt includes
#include <QtGui/QListWidget>

//kde includes
#include <klocale.h>

// app includes
#include "folder.h"
#include "umldoc.h"
#include "uml.h"
#include "classifier.h"
#include "entity.h"



/**
 * Constructor.
 * @param parent   the parent (wizard) of this wizard page
 */
CodeGenSelectPage::CodeGenSelectPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(i18n("Select Classes"));
    setSubTitle(i18n("Place all the classes you want to generate code\nfor in the right hand side list."));

    setupUi(this);

    connect(ui_listAvailable, SIGNAL(itemChanged(QListWidgetItem *)), this, SLOT(selectClass()));
}

/**
 * Destructor.
 */
CodeGenSelectPage::~CodeGenSelectPage()
{
}

/**
 * Loads the available classes for selection / deselection
 * into the list widget.
 * @param classList   the available classes for generation
 */
void CodeGenSelectPage::setClassifierList(UMLClassifierList *classList)
{
    UMLDoc* doc = UMLApp::app()->document();

    UMLClassifierList cList;

    if (classList == NULL) {
        UMLFolder* currRoot = doc->currentRoot();
        Uml::ModelType type = doc->rootFolderType(currRoot);

        switch (type) {
            case Uml::ModelType::Logical:
                cList = doc->classesAndInterfaces();
                break;
            case Uml::ModelType::EntityRelationship:
                foreach (UMLEntity* ent, doc->entities()) {
                    cList.append(ent);
                }
                break;
           default:
                break;
        }
        classList = &cList;
    }

    foreach (UMLClassifier* c, cList) {
        QListWidgetItem* i = new QListWidgetItem(c->fullyQualifiedName(), ui_listAvailable);
        i->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        i->setCheckState(Qt::Unchecked);
    }
}

/**
 * Reimplemented QWizardPage method the enable / disable the next button.
 * @return   complete state
 */
bool CodeGenSelectPage::isComplete() const
{
    for(int row = 0; row < ui_listAvailable->count(); row++)
    {
             QListWidgetItem *item = ui_listAvailable->item(row);
             if (item->checkState() == Qt::Checked)
                return true;
    }
    return false;
}

/**
 * Returns the list widget, which holds the classes for generation.
 * @return   the list widget of the selected classes
 */
QListWidget* CodeGenSelectPage::getSelectionListWidget()
{
    return ui_listAvailable;
}

/**
 * Adds the classes selected in the available classes list to the
 * list of classes used to generate the code.
 */
void CodeGenSelectPage::selectClass()
{

    emit completeChanged();
}

/**
 * Removes the classes selected in the selected classes list from the
 * list of classes used to generate the code.
 */
void CodeGenSelectPage::deselectClass()
{
    emit completeChanged();
}

#include "codegenselectpage.moc"
