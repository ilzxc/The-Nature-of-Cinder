//
//  DNA.cpp
//  Ex91Shakespeare
//
//  Created by Ilya Rostovtsev on 12/25/13.
//
//

#include "DNA.h"

DNA::DNA(){}

DNA::DNA( const int num, std::shared_ptr< ci::Rand > rand ):
random( rand )
{
    for ( auto i = 0; i < num; ++i ) {
        genes.push_back( random->nextInt( 32, 128 ) );
    }
}

std::vector< char > DNA::get_phrase() const
{
    return genes;
}

void DNA::compute_fitness( const std::vector< char >& target )
{
    auto score = 0.f;
    for ( auto i = 0; i < genes.size(); ++i ) {
        if ( genes[ i ] == target[ i ] ) {
            ++score;
        }
    }
    
    fitness = score / target.size();
}

float DNA::get_fitness() const
{
    return fitness;
}

std::shared_ptr< DNA > DNA::crossover( const std::shared_ptr< DNA > partner )
{
    // new child:
    std::shared_ptr< DNA > child = std::make_shared< DNA >();
    auto midpoint = random->randInt( genes.size() ); // pick a midpoint
    
    // half from one, half from the other:
    for ( auto i = 0; i < genes.size(); ++i ) {
        if ( i < midpoint ) {
            child->set_gene( genes[ i ] );
        } else {
            child->set_gene( partner->get_phrase()[ i ] );
        }
    }
    return child;
}

void DNA::mutate( const float mutation_rate )
{
    for ( auto g : genes ) {
        float roll = random->randFloat();
        if ( roll < mutation_rate ) {
            g = random->randInt( 32, 128 ); /* static_cast< char >( random->nextInt( 32, 128 ) ); */
        }
    }
}

void DNA::set_gene( const char value ) {
    genes.push_back( value );
}