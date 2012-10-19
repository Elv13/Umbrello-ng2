/* This file is part of KDevelop
    Copyright (C) 2002,2003 Roberto Raggi <roberto@kdevelop.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "errors.h"
#include <klocale.h>

QT_STATIC_CONST_IMPL Error& Errors::InternalError = Error( 1, -1, ki18n("Internal Error") );
QT_STATIC_CONST_IMPL Error& Errors::SyntaxError = Error( 2, -1, ki18n("Syntax Error before '%1'") );
QT_STATIC_CONST_IMPL Error& Errors::ParseError = Error( 3, -1, ki18n("Parse Error before '%1'") );
