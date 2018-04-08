//
// Created by christ on 08.04.18.
//

#include "FlaseContainer.h"

using namespace Wt;
using namespace std;

FlaseContainer::FlaseContainer()
{
    setContentAlignment( AlignmentFlag::Center );
    
    // init random number generator
    const gsl_rng_type* T;
    gsl_rng* rng;
    long int seed;
    
    gsl_rng_env_setup();
    T = gsl_rng_default;
    rng = gsl_rng_alloc( T );
    time_t t1;
    time( &t1 );
    seed = t1;
    gsl_rng_set( rng, seed );
    
    Dogs dogs = Dogs( *( new BrownianMotion( 4.0, rng, 1.0 ) ) );
    
    
    frame = addWidget( make_unique<Flase>( dogs ) );
}