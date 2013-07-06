//
//  Mover.h
//  Ex15_VectorAccelRandom
//
//  Created by Ilya Rostovtsev on 7/5/13.
//
//

#ifndef __Ex15_VectorAccelRandom__Mover__
#define __Ex15_VectorAccelRandom__Mover__

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    
public:
    Mover(): position( Vec2f::zero() ), velocity( Vec2f(randFloat(20.0f) - 20.0f, randFloat(20.0f) - 20.0f) ), acceleration( Vec2f::zero() ) { }
    ~Mover() { }
    void randomizeAcceleration();
    void update();
    void draw();
};

#endif /* defined(__Ex15_VectorAccelRandom__Mover__) */
