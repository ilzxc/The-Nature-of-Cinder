//
//  Ball.h
//  Ex11_BallWithoutVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex11_BallWithoutVectors__Ball__
#define __Ex11_BallWithoutVectors__Ball__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;


class Ball {
private:
    float x, y;
    float xSpeed, ySpeed;
    float cRadius;
    float green;
    
public:
    Ball() { }
    Ball( float setX, float setY, const Rand& r ): x(setX), y(setY), cRadius(20.0f), xSpeed(r.randFloat(30.0) - (15)), ySpeed(r.randFloat(30.0) - (15)), green(r.randFloat()) { }
    ~Ball() {}
    void update();
    void draw();
};

#endif /* defined(__Ex11_BallWithoutVectors__Ball__) */
