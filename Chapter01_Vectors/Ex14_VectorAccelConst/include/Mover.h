//
//  Mover.h
//  Ex14_VectorAccelConst
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex14_VectorAccelConst__Mover__
#define __Ex14_VectorAccelConst__Mover__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
    
public:
    Mover();
    void randomizeAcceleration();
    void update();
    void draw() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;

};

#endif /* defined(__Ex14_VectorAccelConst__Mover__) */
