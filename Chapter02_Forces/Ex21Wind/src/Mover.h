//
//  Mover.h
//  Ex21Wind
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#ifndef __Ex21Wind__Mover__
#define __Ex21Wind__Mover__

#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float mass;
    float radius;
    
    void checkEdges();
    
public:
    Mover(): location(Vec2f(30.f, 30.f)), velocity(Vec2f::zero()), acceleration(Vec2f::zero()), mass(1.0f), radius(24.0f) { }
    ~Mover() { }
    void applyForce( const Vec2f& force );
    void update();
    void draw();
    
};

#endif /* defined(__Ex21Wind__Mover__) */
