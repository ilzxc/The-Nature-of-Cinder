//
//  Ball.h
//  Ex11_BallWithoutVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/15/13
//

#ifndef __Ex11_BallWithoutVectors__Ball__
#define __Ex11_BallWithoutVectors__Ball__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Ball {
public:
    Ball() { } 
    Ball( const float _x, const float _y, const Rand& _r );

    void update();
    void draw() const;
    
private:
    float x;
    float y;
    float xSpeed;
    float ySpeed;
    float cRadius;
    float grey;
};

#endif /* defined(__Ex11_BallWithoutVectors__Ball__) */
