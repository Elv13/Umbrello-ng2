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

#ifndef ERRORS_H
#define ERRORS_H

#include <klocalizedstring.h>

struct Error{
    int code;
    int level;
    KLocalizedString text;

    Error( int c, int l, const KLocalizedString& s )
        : code( c ), level( l ), text( s )
        {}
};

class Errors{
public:
    QT_STATIC_CONST Error& InternalError;
    QT_STATIC_CONST Error& SyntaxError;
    QT_STATIC_CONST Error& ParseError;
};

#endif
