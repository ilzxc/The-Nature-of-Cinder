//
//  Population.cpp
//  Ex91Shakespeare
//
//  Created by Ilya Rostovtsev on 12/25/13.
//
//

#include "Population.h"

Population::Population( const std::vector< char >& _target, const float m, const int num, std::shared_ptr< ci::Rand > rand )
: target{ _target },
  mutation_rate{ m },
  finished{ false },
  generations{ 0 },
  perfect_score{ 1 },
  random{ rand }
{
    random->randomize();
    int target_length = target.size();
    for ( auto i = 0; i < num; ++i ) {
        population.push_back( std::make_shared< DNA >( target_length, random ) );
    }
    
    compute_fitness();
}

void Population::compute_fitness()
{
    for ( auto& p : population ) {
        p->compute_fitness( target );
    }
}

void Population::natural_selection()
{
    mating_pool.clear();
    
    auto max_fitness = 0.f;
    for ( auto& p : population ) {
        if ( p->get_fitness() > max_fitness ) {
            max_fitness = p->get_fitness();
        }
    }
    
    // Add to the mating pool:
    for ( auto& p : population ) {
        auto fitness = p->get_fitness() / max_fitness;
        auto n = static_cast< int >( fitness * 100 );
        for ( auto j = 0; j < n; ++j ) {
            mating_pool.push_back( p );
        }
    }
    generate();
    compute_fitness();
}

void Population::generate()
{
    int total_num = population.size();
    population.clear();
    // refill the population with children from the mating pool:
    for ( auto i = 0; i < total_num; ++i ) {
        int a = random->nextInt( mating_pool.size() );
        int b = random->nextInt( mating_pool.size() );
        std::shared_ptr< DNA > child = mating_pool[ a ]->crossover( mating_pool[ b ] );
        child->mutate( mutation_rate );
        population.push_back( child );
    }
    ++generations;
}

std::vector< char > Population::get_best()
{
    auto world_record = 0.f;
    auto index = 0;
    for ( auto i = 0; i < population.size(); ++i ) {
        if ( population[ i ]->get_fitness() > world_record ) {
            index = i;
            world_record = population[ i ]->get_fitness();
        }
    }
    
    if ( world_record == perfect_score ) { finished = true; }
    return population[ index ]->get_phrase();
    
}

bool Population::is_finished() const
{
    return finished;
}

int Population::get_generations() const
{
    return generations;
}

float Population::get_average_fiteness() const
{
    auto total = 0.f;
    for ( auto& p : population ) {
        total += p->get_fitness();
    }
    
    return total / ( population.size() );
}

std::vector< char > Population::all_phrases() const
{
    std::vector< char > everything;
    int population_size = population.size();
    auto display_limit = std::min( population_size, 50 );
    for ( auto i = 0; i < display_limit; ++i ) {
        std::vector< char > to_add = population[ i ]->get_phrase();
        for ( auto c : to_add ) {
            everything.push_back( c );
        }
        everything.push_back( '\n' );
    }
    return everything;
}