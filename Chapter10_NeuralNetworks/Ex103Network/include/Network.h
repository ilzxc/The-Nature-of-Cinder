//
//  Network.h
//  Ex103Network
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#ifndef __Ex103Network__Network__
#define __Ex103Network__Network__

#pragma once
#include <vector>
#include "cinder/gl/gl.h"
#include "Neuron.h"
#include "Connection.h"

class Network
{
  public:
    Network( const float x, const float y );
    void addNeuron( std::shared_ptr< Neuron > n );
    void connect( std::shared_ptr< Neuron > a, std::shared_ptr< Neuron > b, const float weight );
    void feedforward( const float input );
    void update();
    void draw() const;
    
  private:
    std::vector< std::shared_ptr< Neuron > > neurons;
    std::vector< std::shared_ptr< Connection > > connections;
    ci::Vec2f location;
};

#endif /* defined(__Ex103Network__Network__) */
