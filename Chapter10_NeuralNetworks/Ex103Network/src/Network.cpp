//
//  Network.cpp
//  Ex103Network
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#include "Network.h"

using namespace std;
using namespace ci;

Network::Network( const float x, const float y )
: location( x, y )
{
}

void Network::addNeuron( shared_ptr< Neuron > n )
{
    neurons.push_back( n );
}

void Network::connect( shared_ptr< Neuron > a, shared_ptr< Neuron > b, const float weight )
{
    shared_ptr< Connection > c = make_shared< Connection >( a, b, weight );
    connections.push_back( c );
}

void Network::feedforward( const float input )
{
    neurons[ 0 ]->feedforward( input );
}

void Network::update()
{
    for ( auto& c : connections ) {
        c->update();
    }
    for ( auto& n : neurons ) {
        if ( n->getSum() > 1 ) {
            n->fire();
            n->resetSum();
        }
    }
}

void Network::draw() const
{
    gl::pushMatrices();
    gl::translate( location );
    for ( auto& n : neurons ) {
        n->draw();
    }
    for ( auto& c : connections ) {
        c->draw();
    }
    gl::popMatrices();
}
