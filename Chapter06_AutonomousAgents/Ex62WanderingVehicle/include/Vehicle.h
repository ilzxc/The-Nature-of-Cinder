//
//  Vehicle.h
//  Ex62WanderingVehicle
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#ifndef Ex62WanderingVehicle_Vehicle_h
#define Ex62WanderingVehicle_Vehicle_h

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Vehicle {
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float wanderTheta;
    float size;
    float maxForce;
    float maxSpeed;
    float angle;
    
    // debug vars:
    bool debug;
    Vec2f circle;
    Vec2f target;
    float wanderR;
    float wanderD;
    float change;
    
    void wander();
    void drawWander() const ;
    void borders();
    void seek( const Vec2f& target );
    
public:
    Vehicle() {}
    Vehicle( Vec2f _position )
    : position( _position ),
      velocity( 1.0f, 1.0f ),
      acceleration( Vec2f::zero() ),
      wanderTheta( 0.0f ),
      size( 16.0f ),
      maxForce( 0.2f ),
      maxSpeed( 3.0f ),
      angle( 0.0f ),
      debug( false ),
      circle( Vec2f::zero() ),
      target( Vec2f::zero() ),
      wanderR( 45.0f ),
      wanderD( 200.0f ),
      change( 0.3f ) {
          std::cout << velocity.x << ", " << velocity.y << std::endl;
      }
    
    void toggleDebug();
    void update();
    void draw() const;
};

#endif
