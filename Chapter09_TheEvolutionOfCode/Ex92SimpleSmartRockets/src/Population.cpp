//
//  Population.cpp
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#include "Population.h"

Population::Population( const float m, const int num, const int lifetime, shared_ptr< Rand > rand )
: mutation_rate( m ),
  generations( 0 ),
  random( rand ),
  location( app::getWindowWidth() / 2.f, app::getWindowHeight() + 20 )
{
    for ( auto i = 0; i < num; ++i ) {
        population.push_back( make_shared< Rocket >( location, make_shared< DNA >( lifetime, random ), num ) );
    }
}

void Population::live( const vector< shared_ptr< Obstacle > > obstacles, const shared_ptr< Obstacle > target )
{
    for ( auto& r : population ) {
        r->check_target( target );
        r->run( obstacles );
    }
}

bool Population::target_reached() const
{
    for ( auto& r : population ) {
        if ( r->get_hit_target() ) {
            return true;
        }
    }
    return false;
}

void Population::fitness()
{
    for ( auto& r : population ) {
        r->compute_fitness();
    }
}

void Population::selection()
{
    mating_pool.clear();
    float max_fitness = get_max_fitness();
    
    for ( auto& r : population ) {
        float fitness_normal = r->get_fitness() / max_fitness;
        int n = static_cast< int >( fitness_normal * 100 );
        for ( auto j = 0; j < n; ++j ) {
            mating_pool.push_back( r );
        }
    }
}

void Population::reproduction()
{
    for ( auto& r : population ) {
        int m = random->randInt( mating_pool.size() );
        int d = random->randInt( mating_pool.size() );
        shared_ptr< Rocket > mom = mating_pool[ m ];
        shared_ptr< Rocket > dad = mating_pool[ d ];
        shared_ptr< DNA > mom_genes = mom->get_dna();
        shared_ptr< DNA > dad_genes = dad->get_dna();
        shared_ptr< DNA > child = mom_genes->crossover( dad_genes );
        child->mutate( mutation_rate );
        r.reset();
        r = make_shared< Rocket >( location, child, population.size() );
    }
    ++generations;
}

int Population::get_generations() const
{
    return generations;
}

float Population::get_max_fitness() const
{
    float record = 0.f;
    for ( auto& r : population ) {
        float eval = r->get_fitness();
        if ( eval > record ) {
            record = eval;
        }
    }
    return record;
}