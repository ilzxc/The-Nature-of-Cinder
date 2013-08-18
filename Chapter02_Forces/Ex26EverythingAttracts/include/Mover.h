//
//  Mover.h
//  Ex26EverythingAttracts
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex26EverythingAttracts__Mover__
#define __Ex26EverythingAttracts__Mover__

#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
public:
    Mover(): radius( 0.0f ), mass( 0.0f ) { }
    Mover( const float _mass, const float _x, const float _y );

    float getMass() const;
    Vec2f getLocation() const;
    Vec2f getVelocity() const;
    void applyForce( const Vec2f& force );
    void update();
    void draw() const;
    Vec2f attract( const Mover& m, const float g ) const;
    
    
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    Vec2f lastAcceleration;
    const float radius;
    const float mass;
};

#endif /* defined(__Ex26EverythingAttracts__Mover__) */
