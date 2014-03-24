//
//  Neuron.h
//  Ex103Network
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#ifndef __Ex103Network__Neuron__
#define __Ex103Network__Neuron__

#include "cinder/Vector.h"

class Neuron
{
  public:
    Neuron( const float x, const float y );
    void feedforward( const float input );
    void fire();
    void draw();
    ci::Vec2f getLocation() const;
    float getSum() const;
    void resetSum();
    
  private:
    ci::Vec2f location;
    float sum, r;
};

#endif /* defined(__Ex103Network__Neuron__) */
