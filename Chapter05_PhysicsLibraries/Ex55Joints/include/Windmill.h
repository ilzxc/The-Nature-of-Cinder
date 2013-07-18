//
//  Windmill.h
//  Ex55Joints
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#ifndef Ex55Joints_Windmill_h
#define Ex55Joints_Windmill_h

#pragma once
#include "Box2D/Box2D.h"
#include "Conversions.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Windmill {
private:
    Vec2f            position;
    Vec2f            bladesPosition;
    Rectf            baseBox;
    Rectf            bladesBox;
    float            bladesAngle;
    b2RevoluteJoint *joint;
    b2Body          *base;
    b2Body          *blades;
    
public:
    Windmill() { }
    Windmill( b2World *world, const Vec2f &_position );
    void update();
    void draw() const;
    void toggleMotor();
    void killBody( b2World *world );
};

#endif
