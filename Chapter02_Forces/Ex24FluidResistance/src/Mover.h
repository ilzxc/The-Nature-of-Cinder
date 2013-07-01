//
//  Mover.h
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 5/20/13.
//
//

#ifndef __Ex24FluidResistance__Mover__
#define __Ex24FluidResistance__Mover__

#include <iostream>
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

class Mover {
public:
    
    Mover() {
        mass = 5.0f;
        location.set(0.0f, 0.0f);
        velocity.set(0.0f, 0.0f);
        acceleration.set(0.0f, 0.0f);
    }
    
    Mover( float m, float x, float y )
    : location(x, y),
      velocity(0.0f, 0.0f),
      acceleration(0.0f, 0.0f),
      mass(m) {
    }
    
    virtual ~Mover() { }
    
    void applyForce(ci::Vec2f const& force);
    void update();
    void draw();
    void checkEdges();
    
    ci::Vec2f location, velocity, acceleration;
    float mass;
    
};

#endif /* defined(__Ex24FluidResistance__Mover__) */
