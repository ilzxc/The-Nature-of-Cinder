//
//  Vehicle.h
//  Ex63StayingWithinWalls
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#ifndef Ex63StayingWithinWalls_Vehicle_h
#define Ex63StayingWithinWalls_Vehicle_h

#include "cinder/gl/gl.h"

using namespace ci;

class Vehicle {
private:
    float boundaryPercent;
    Rectf bounds;
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float size;
    float maxForce;
    float maxSpeed;
    float angle;
    
    void applyForce( const Vec2f& force );
    void boundaries();
    
public:
    Vehicle() {}
    Vehicle( const Vec2f& _position, const Vec2f& dimensions )
    : boundaryPercent( 0.1f ),
      position( _position ),
      velocity( 10.0f, 10.0f ),
      acceleration( Vec2f::zero() ),
      size( 16.0f ),
      maxForce( 0.2f ),
      maxSpeed( 4.0f ),
      angle( 0.0f ) {
          setBoundary( dimensions );
    }
    
    void setBoundary( const Vec2f& dimensions );
    void update();
    void draw() const;
};

#endif
