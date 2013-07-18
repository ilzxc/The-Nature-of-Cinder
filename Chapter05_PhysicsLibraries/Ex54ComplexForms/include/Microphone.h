//
//  Microphone.h
//  Ex54ComplexForms
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#ifndef Ex54ComplexForms_Microphone_h
#define Ex54ComplexForms_Microphone_h

#pragma once
#include "Box2D/Box2D.h"
#include "Conversions.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Microphone {
private:
    b2Body *body;
    Vec2f  position;
    Rectf  box;
    float  radius;
    float  angle;
    
public:
    Microphone() { }
    Microphone( b2World *world, const Vec2f &_position );
    void update();
    void draw() const;
    bool isDead() const;
    void killBody( b2World *world );
};

#endif
