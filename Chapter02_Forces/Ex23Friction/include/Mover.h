//
//  Mover.h
//  Ex23Friction
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex23Friction__Mover__
#define __Ex23Friction__Mover__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
    
public:
    Mover( const float mass_, const float x, const float y );

    float getMass() const;
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

#endif /* defined(__Ex23Friction__Mover__) */
