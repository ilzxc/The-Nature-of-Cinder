//
//  Neuron.cpp
//  Ex103Network
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#include "Neuron.h"

using namespace std;
using namespace ci;

Neuron::Neuron( const float x, const float y )
: location( x, y ),
  sum( 0.f ),
  r( 16.f )
{
}

void Neuron::feedforward( const float input )
{
    sum += input;
}

void Neuron::fire()
{
    r = 32.f;
}

void Neuron::draw()
{
    gl::color( 0.f, 0.f, 0.f );
    gl::lineWidth( 1.f );
    gl::drawStrokedCircle( location, r );
    gl::color( 0.f, 0.f, 0.f, sum );
    gl::drawSolidCircle( location, r );
    r = lerp( r, 16.f, 0.03f );
}

Vec2f Neuron::getLocation() const
{
    return location;
}

float Neuron::getSum() const
{
    return sum;
}

void Neuron::resetSum()
{
    sum = 0.f;
}
