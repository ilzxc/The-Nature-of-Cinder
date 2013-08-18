//
//  Mover.h
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex24FluidResistance__Mover__
#define __Ex24FluidResistance__Mover__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
public:
    Mover( float m, float x, float y );

    float getMass() const;
    Vec2f getLocation() const;
    Vec2f getVelocity() const;
    void applyForce( const Vec2f& force );
    void update();
    void draw() const;
    
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    const float radius;
    const float mass;
    
    void checkEdges();
};

#endif /* defined(__Ex24FluidResistance__Mover__) */
