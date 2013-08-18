//
//  SpaceShip.h
//  Ex33Asteroids
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex33Asteroids__SpaceShip__
#define __Ex33Asteroids__SpaceShip__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;

class SpaceShip {    
public:
    SpaceShip( const float _x, const float _y );
    
    void update( const bool keys[] );
    void draw() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    const float damping;
    const float topspeed;
    float heading;
    const float r;
    bool thrusting;
    
    void wrapEdges();

};

#endif /* defined(__Ex33Asteroids__SpaceShip__) */
