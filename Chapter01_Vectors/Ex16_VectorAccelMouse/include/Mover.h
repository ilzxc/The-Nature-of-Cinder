//
//  Mover.h
//  Ex16_VectorAccelMouse
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#ifndef __Ex16_VectorAccelMouse__Mover__
#define __Ex16_VectorAccelMouse__Mover__

#include "cinder/Vector.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
public:
    Mover(): position( Vec2f::zero() ), velocity ( Vec2f::zero() ), acceleration ( Vec2f::zero() ) { }
    ~Mover() {}
    void update( const Vec2f& mousePosition);
    void draw();
    
private:
    ci::Vec2f position;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
};

#endif /* defined(__Ex16_VectorAccelMouse__Mover__) */
