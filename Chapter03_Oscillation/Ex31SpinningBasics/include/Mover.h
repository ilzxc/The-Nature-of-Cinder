//
//  Mover.h
//  Ex31SpinningBasics
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17
//

#ifndef __Ex31SpinningBasics__Mover__
#define __Ex31SpinningBasics__Mover__

#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
public:
    Mover( const float _mass, const float _x, const float _y );
    
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
    const Rectf bounds;
    float angleAcceleration;
    float angleVelocity;
    float angle;
    const float mass;
};

#endif /* defined(__Ex31SpinningBasics__Mover__) */
