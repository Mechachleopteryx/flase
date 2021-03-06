/*
Copyright (C) 2017  Simon Christ <c.O_o.l@web.de>, Jörg Bachmann <explicit@explicits.de>

This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _COMMON_PRINTING_H
#define _COMMON_PRINTING_H

#include <iostream>

#include "Camera.h"

std::ostream& operator<<( std::ostream& out, const RVec& vec );

template< typename T >
std::ostream& operator<<( std::ostream& out, const Vec< T >& vec )
{
        return out << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")";
}

std::ostream& operator<<( std::ostream& out, const Camera& cam );

std::ostream& operator<<( std::ostream& out, const Matrix& m );

#endif // _COMMON_PRINTING
