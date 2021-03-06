
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
#include "InfiniteSimulation.h"

using namespace std;

InfiniteSimulation::InfiniteSimulation( HarryPlotter& plotter, real meanSheepDiffusionTime, gsl_rng* const rng, Measure& measure, real dt ) :
    Simulation( plotter, meanSheepDiffusionTime, rng, measure ),
    dt( dt )
{
}

real InfiniteSimulation::run( )
{
    World& world = World::instance();

    size_t i = 0;
    while( true ) {
        iterate( dt );

        time += dt;
        ++i;

        plotter.plot( world, time );
    }
    
    return time;
}

