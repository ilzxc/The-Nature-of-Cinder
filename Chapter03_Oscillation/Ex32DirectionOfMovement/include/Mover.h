//
//  Mover.h
//  Ex32DirectionOfMovement
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex32DirectionOfMovement__Mover__
#define __Ex32DirectionOfMovement__Mover__

#include "cinder/Vector.h"
#include "cinder/Rand.h"

using namespace ci;

class Mover {
public:
    Mover(): position( Vec2f::zero() ), velocity( Vec2f::zero() ), acceleration( Vec2f::zero() ), bounds( -10, -5, 10, 5 ), dotBounds( -3, -3, 3, 3 ) { }
    ~Mover() {}
    void update( const Vec2f& mousePosition );
    void draw();
    
private:
    ci::Vec2f position;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
    float angle;
    Rectf bounds;
    Rectf dotBounds;
};

#endif /* defined(__Ex32DirectionOfMovement__Mover__) */
