//
//  Perceptron.cpp
//  Ex101SimplePerceptron
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#include "Perceptron.h"

using namespace ci;

Perceptron::Perceptron( const int n, const float c_, shared_ptr< Rand > random ): c( c_ )
{
    for ( auto i = 0; i < n; ++i ) {
        weights.push_back( random->nextFloat( -1.f, 1.f ) );
    }
}

void Perceptron::train( const vector< float >& inputs, const int desired )
{
    // guess the result:
    int guess = feedforward( inputs );
    // compute the factor for changing the weight based on the error;
    // Error = desired output - guessed output
    // Note that the error can only be 0, -2, or 2
    // Multiply by the learning constant:
    float error = desired - guess;
    for ( auto i = 0; i < weights.size(); ++i ) {
        weights[ i ] += c * error * inputs[ i ];
    }
}

/// guess -1 or 1 based on input values
int Perceptron::feedforward( const vector< float >& inputs ) const
{
    float sum = 0;
    for ( auto i = 0; i < weights.size(); ++i ) {
        sum += inputs[ i ] * weights[ i ];
    }
    return activate( sum );
}

int Perceptron::activate( const float sum ) const
{
    if ( sum > 0 ) {
        return 1;
    }
    return -1;
}

vector< float > Perceptron::getWeights() const
{
    return weights;
}