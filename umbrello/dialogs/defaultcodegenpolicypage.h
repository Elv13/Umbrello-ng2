/****************************************************************************
** Form interface generated from reading ui file 'Defaultcodegenpolicypage.ui'
**
** Created: Fri Aug 1 12:47:23 2003
**      by: The User Interface Compiler ($Id: defaultcodegenpolicypage.h 1258247 2011-10-10 18:32:08Z fischer $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DEFAULTCODEGENPOLICYPAGE_H
#define DEFAULTCODEGENPOLICYPAGE_H

#include "codegenerationpolicypage.h"

class QLabel;
class QWidget;

class DefaultCodeGenPolicyPage : public CodeGenerationPolicyPage
{
    Q_OBJECT
public:
    explicit DefaultCodeGenPolicyPage(QWidget* parent = 0, const char* name = 0, CodeGenPolicyExt * policy =0);
    ~DefaultCodeGenPolicyPage();

private:
    QLabel* m_textLabel;

};

#endif // DEFAULTCODEGENPOLICYPAGE_H
