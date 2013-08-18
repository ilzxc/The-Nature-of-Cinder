//
//  Mover.h
//  Ex15_VectorAccelRandom
//
//  Created by Ilya Rostovtsev on 7/5/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex15_VectorAccelRandom__Mover__
#define __Ex15_VectorAccelRandom__Mover__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
public:
    Mover();
    void randomizeAcceleration();
    void update();
    void draw();
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
};

#endif /* defined(__Ex15_VectorAccelRandom__Mover__) */
