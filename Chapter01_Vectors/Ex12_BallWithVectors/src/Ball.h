//
//  Ball.h
//  Ex12_BallWithVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex12_BallWithVectors__Ball__
#define __Ex12_BallWithVectors__Ball__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Ball {
private:
    Vec2f position, velocity;
    float radius;
    
public:
    
    Ball() {}
    Ball( float x, float y ) : position( x, y ), velocity( randFloat(-10.0f, 10.0f), randFloat( -10.0, 10.0f ) ), radius( 30.0f ) { }
    Ball( const Vec2f& p ): Ball::Ball( p.x, p.y ) { }
    ~Ball() {}
    
    void update();
    void draw();
};

#endif /* defined(__Ex12_BallWithVectors__Ball__) */
