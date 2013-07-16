//
//  Vehicle.h
//  Ex64FlowFieldFollowing
//
//  Created by Ilya Rostovtsev on 7/16/13.
//
//

#ifndef Ex64FlowFieldFollowing_Vehicle_h
#define Ex64FlowFieldFollowing_Vehicle_h

#include "cinder/gl/gl.h"
#include "FlowField.h"

using namespace ci;

class Vehicle {
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float size;
    float maxForce;
    float maxSpeed;
    float angle;
    
	void borders();
    
public:
    Vehicle() {}
    Vehicle( const Vec2f& _position, float _maxforce, float _maxspeed )
    : position( _position ),
      velocity( Vec2f::zero() ),
      acceleration( Vec2f::zero() ),
      size( 5.0f ),
      maxForce( _maxforce ),
      maxSpeed( _maxspeed ),
      angle( 0.0f )
    { }
    
    void update( const FlowField& flow );
    void draw() const;
};

#endif
