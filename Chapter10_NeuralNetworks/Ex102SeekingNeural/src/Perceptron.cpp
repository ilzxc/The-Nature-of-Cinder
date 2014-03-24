//
//  Perceptron.cpp
//  Ex102SeekingNeural
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#include "Perceptron.h"

Perceptron::Perceptron( const int n, const float c, shared_ptr< Rand >  random )
: c( c )
{
    for ( auto i = 0; i < n; ++i ) {
        weights.push_back( random->randFloat( 0.f, 1.f ) );
    }
}

void Perceptron::train( const vector< Vec2f >& forces, const Vec2f& error )
{
    for ( auto i = 0; i < weights.size(); ++i ) {
        weights[ i ] += c * error.x * forces[ i ].x;
        weights[ i ] += c * error.y * forces[ i ].y;
        weights[ i ] = constrain( weights[ i ], 0.f, 1.f );
    }
}

Vec2f Perceptron::feedforward( const vector< Vec2f >& forces )
{
    Vec2f sum = Vec2f::zero();
    for ( auto i = 0; i < weights.size(); ++i ) {
        sum += forces[ i ] * weights[ i ];
    }
    return sum;
}
