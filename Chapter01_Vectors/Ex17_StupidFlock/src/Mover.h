//
//  Mover.h
//  Ex17_StupidFlock
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#ifndef __Ex17_StupidFlock__Mover__
#define __Ex17_StupidFlock__Mover__

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
public:
    Mover() { }
    Mover( float fat ): fatness(fat), position( Vec2f::zero() ), velocity( Vec2f::zero() ), acceleration( Vec2f::zero() ) { }
    ~Mover() { }
    void setAccel( cinder::Vec2f );
    void update();
    void draw();
    
    float fatness;
    
private:
    const int fatMax = 10.0;
    ci::Vec2f position;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
};

#endif /* defined(__Ex17_StupidFlock__Mover__) */
