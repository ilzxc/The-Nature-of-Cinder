//
//  Mover.h
//  Ex23Friction
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#ifndef __Ex23Friction__Mover__
#define __Ex23Friction__Mover__

#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float radius;
    float mass;
    void checkEdges();
    
public:
    Mover() { }
    Mover( float m, float x, float y ): location(Vec2f(x, y)), velocity(Vec2f::zero()), acceleration(Vec2f::zero()), mass(m), radius(m * 8) { }
    ~Mover() { }
    void applyForce( const Vec2f& force );
    void update();
    void draw();
    float getMass();
    Vec2f getVelocity();

};

#endif /* defined(__Ex23Friction__Mover__) */
