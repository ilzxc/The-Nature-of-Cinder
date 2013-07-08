//
//  SpaceShip.h
//  Ex33Asteroids
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex33Asteroids__SpaceShip__
#define __Ex33Asteroids__SpaceShip__

#include "cinder/gl/gl.h"
#include "math.h"

using namespace ci;

class SpaceShip {
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float damping;
    float topspeed;
    float heading;
    float r;
    bool thrusting;
    
    void wrapEdges();
    
public:
    SpaceShip() { }
    SpaceShip(float x, float y)
    : position( x, y ),
      velocity( Vec2f::zero() ),
      acceleration( Vec2f::zero() ),
      damping( 0.995f ),
      topspeed( 6.0f ),
      heading( 0.0f ),
      r( 8.0f ),
      thrusting( 0.0f ) {
    }
    ~SpaceShip() { }
    
    void update( const bool keys[] );
    void draw();
};

#endif /* defined(__Ex33Asteroids__SpaceShip__) */
