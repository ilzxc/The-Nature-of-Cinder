//
//  Connection.h
//  Ex103Network
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#ifndef __Ex103Network__Connection__
#define __Ex103Network__Connection__

#include "Neuron.h"

class Connection
{
public:
    Connection( std::shared_ptr< Neuron > from, std::shared_ptr< Neuron > to, const float w );
    void feedforward( const float val );
    void update();
    void draw() const;
    void checkFire();
    
private:
    std::shared_ptr< Neuron > a, b;
    float weight;
    bool sending;
    float output;
    ci::Vec2f sender;
};
    
#endif /* defined(__Ex103Network__Connection__) */
