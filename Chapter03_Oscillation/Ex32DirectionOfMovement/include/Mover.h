//
//  Mover.h
//  Ex32DirectionOfMovement
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex32DirectionOfMovement__Mover__
#define __Ex32DirectionOfMovement__Mover__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
    
public:
    Mover();
    void update( const Vec2f& mousePosition );
    void draw() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float angle;
    const Rectf bounds;
    const Rectf dotBounds;

};

#endif /* defined(__Ex32DirectionOfMovement__Mover__) */
