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

#include "common.h"
#include "DoMeasure.h"

using namespace std;

DoMeasure::DoMeasure( size_t skip, string filename ) :
        Measure( skip, filename )
{
}

DoMeasure::~DoMeasure()
{
    out.flush();
}

void DoMeasure::init( )
{
    World& world = World::instance();
    
    mqdNorm = meanQuadraticDistance( world.sheep );
}

void DoMeasure::measure( const World& world, real time )
{
    if( skipcounter % skip == 0 )
    {
        // center of mass
        real x;
        real y;
        
        world.sheep.getCenterOfMass( x, y );
        
        real dl = world.boxsize / world.sheep.size();
        real rcl = world.sheep.getClusterRadius() ;
        
        msdNorm =  rcl * rcl /  2 + rcl * dl / 2;
        msdValue = ( msdNorm / meanSquareDisplacement( world.sheep ) );
        mqdValue = ( meanQuadraticDistance( world.sheep ) / mqdNorm );
        
        {
            out << x << "\t" << y << "\t";
            
            out << mqdValue << "\t";
            out << msdValue << "\t";
            out << time;
            out << "\n\n\n";
        }
        
        //output: cmx cmy MQD MSD time (triple newline for gnuplot compability)
    }
    
    ++skipcounter;
}


