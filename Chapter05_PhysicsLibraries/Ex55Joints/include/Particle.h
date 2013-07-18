//
//  Particle.h
//  Ex55Joints
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#ifndef Ex55Joints_Particle_h
#define Ex55Joints_Particle_h

#pragma once
#include "Box2D/Box2D.h"
#include "Conversions.h"
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
private:
    b2Body *body;
    Vec2f  position;
    float  angle;
    float  radius;
    
public:
    Particle() { }
    Particle( b2World *world, const Vec2f &_position, float _radius );
    void update();
    void draw() const;
    b2Body* getBody() const;
    bool isDead() const;
    void killBody( b2World *world );
};

#endif
