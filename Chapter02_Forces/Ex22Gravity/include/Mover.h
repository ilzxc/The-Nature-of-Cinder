//
//  Mover.h
//  Ex22Gravity
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex22Gravity__Mover__
#define __Ex22Gravity__Mover__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
public:
    Mover(): radius( 10.0f ), mass( 80.0f ) { }
    Mover( const float _mass, const float _x, const float _y );

    float getMass() const;
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

#endif /* defined(__Ex22Gravity__Mover__) */
