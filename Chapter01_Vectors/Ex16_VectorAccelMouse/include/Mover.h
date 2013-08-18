//
//  Mover.h
//  Ex16_VectorAccelMouse
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex16_VectorAccelMouse__Mover__
#define __Ex16_VectorAccelMouse__Mover__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
public:
    Mover();
    void update( const Vec2f& mousePosition);
    void draw() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
};

#endif /* defined(__Ex16_VectorAccelMouse__Mover__) */
