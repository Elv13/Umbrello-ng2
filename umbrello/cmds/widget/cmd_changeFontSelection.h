/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2002-2009                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

#ifndef CMD_CHANGEFONTSELECTION_H
#define CMD_CHANGEFONTSELECTION_H

#include <QFont>
#include <QUndoCommand>

class UMLDoc;
class UMLScene;

namespace Uml
{
    class CmdChangeFontSelection: public QUndoCommand
    {
        public:
            CmdChangeFontSelection(UMLDoc* doc, UMLScene* scene, QFont fon);

            void undo();
            void redo();

        private:
            UMLDoc*   m_doc;
            UMLScene* m_scene;
            QFont     m_newFont;
            QFont     m_oldFont;
    };
}

#endif // CMD_CHANGEFONTSELECTION_H
