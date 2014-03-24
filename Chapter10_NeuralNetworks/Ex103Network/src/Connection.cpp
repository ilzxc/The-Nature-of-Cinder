//
//  Connection.cpp
//  Ex103Network
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#include "Connection.h"

using namespace std;
using namespace ci;

Connection::Connection( shared_ptr< Neuron > from, shared_ptr< Neuron > to, const float w )
: a( from ),
  b( to ),
  weight( w ),
  sending( false ),
  output( 0.f ),
  sender( Vec2f::zero() )
{

}

void Connection::feedforward( const float val )
{
    output = val * weight; // compute output
    sender = a->getLocation();
    sending = true;
}

void Connection::checkFire()
{
    if ( a->getSum() > 1 ) {
        feedforward( a->getSum() );
    }
}

void Connection::update()
{
    if ( sending ) {
        sender = lerp( sender, b->getLocation(), Vec2f( 0.1f, 0.1f ) );
        float d = sender.distance( b->getLocation() );
        if ( d < 1 ) {
            b->feedforward( output );
            sending = false;
        }
    }
    checkFire();
}

void Connection::draw() const
{
    gl::color( 0.f, 0.f, 0.f );
    gl::lineWidth( 1 + weight * 3.f );
    gl::drawLine( a->getLocation(), b->getLocation() );
    if ( sending ) {
        gl::lineWidth( 1.f );
        gl::drawSolidCircle( sender, 8.f );
    }
}
