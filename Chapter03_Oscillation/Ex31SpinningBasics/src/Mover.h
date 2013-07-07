//
//  Mover.h
//  Ex31SpinningBasics
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex31SpinningBasics__Mover__
#define __Ex31SpinningBasics__Mover__

#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    Rectf bounds;
    float angleAcceleration;
    float angleVelocity;
    float angle;
    float mass;
    
public:
    Mover() { }
    Mover( float m, float x, float y ): location( x, y ), velocity( Vec2f::zero() ), acceleration( Vec2f::zero() ), mass(m), bounds( -m * 8, -m * 8, m * 8, m * 8 ) { }
    ~Mover() { }
    void applyForce( const Vec2f& force );
    void update();
    void draw();
    float getMass() const;
    Vec2f getLocation() const;
    Vec2f getVelocity() const;
    
};

#endif /* defined(__Ex31SpinningBasics__Mover__) */
