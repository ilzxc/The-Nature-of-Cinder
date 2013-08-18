//
//  Mover.h
//  Ex17_StupidFlock
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//  HWH Maintenance 8/17/13
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
    Mover( const float _fatness );
    
    void setAccel( const Vec2f& mousePosition );
    void update();
    void draw() const;
    
private:
    float fatness;
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
};

#endif /* defined(__Ex17_StupidFlock__Mover__) */
