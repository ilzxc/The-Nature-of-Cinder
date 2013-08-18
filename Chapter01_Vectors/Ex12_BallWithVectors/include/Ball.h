//
//  Ball.h
//  Ex12_BallWithVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex12_BallWithVectors__Ball__
#define __Ex12_BallWithVectors__Ball__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Ball {
public:
    Ball() { }                                // "default constructor"
    Ball( const Vec2f& _p );                  // constructing using a Vec2f
    Ball( const float _x, const float _y );   // constructing using two floats
    
    void update();
    void draw();
    
private:
    Vec2f position;
    Vec2f velocity;
    float radius;
};

#endif /* defined(__Ex12_BallWithVectors__Ball__) */
