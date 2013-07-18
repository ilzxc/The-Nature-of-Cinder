//
//  Pair.h
//  Ex55Joints
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#ifndef Ex55Joints_Pair_h
#define Ex55Joints_Pair_h

#pragma once
#include "Particle.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Pair {
private:
    Vec2f lineStart;
    Vec2f lineEnd;
    Particle pair[2];
    float length;
    
public:
    Pair() { }
    Pair( b2World *world, const Vec2f &_position );
    void update();
    void draw() const;
    bool isDead() const;
    void killBody( b2World *world );
};


#endif
