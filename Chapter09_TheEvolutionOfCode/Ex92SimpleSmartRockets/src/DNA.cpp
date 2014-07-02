//
//  DNA.cpp
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#include "DNA.h"

DNA::DNA( const int lifetime, shared_ptr< Rand > random ): max_force( 0.1f ), rand( random )
{
    for ( auto i = 0; i < lifetime; ++i ) {
        float angle = rand->randFloat( M_2_PI );
        Vec2f to_add = Vec2f( cos( angle ), sin( angle ) );
        to_add *= max_force;
        genes.push_back( to_add );
    }
    genes[ 0 ].normalize(); // boost during the first frame
}

DNA::DNA( const vector< Vec2f >& new_genes, shared_ptr< Rand > random ): max_force( 0.1f ), genes( new_genes ), rand( random )
{
}

shared_ptr< DNA > DNA::crossover( const shared_ptr< DNA > partner )
{
    vector< Vec2f > child;
    int crossover = rand->randInt( genes.size() );
    for ( auto i = 0; i < genes.size(); ++i ) {
        if ( i > crossover ) {
            child[ i ] = genes[ i ];
        } else {
            child[ i ] = partner->genes[ i ];
        }
    }
    shared_ptr< DNA > new_genes = make_shared< DNA >( child, rand );
    return new_genes;
}

void DNA::mutate( const float m )
{
    for ( auto gene : genes ) {
        if ( rand->randFloat() < m ) {
            float angle = rand->randFloat( M_2_PI );
            Vec2f mutated = Vec2f( cos( angle ), sin( angle ) );
            mutated *= rand->randFloat( 0.f, max_force );
            gene = mutated;
        }
    }
    genes[ 0 ].normalize();
}