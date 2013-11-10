//
//  Vehicle.h
//  Ex61SelfSteeringVehicle
//
//  Created by Ilya Rostovtsev on 7/15/13.
//
//

#ifndef Ex61SelfSteeringVehicle_Vehicle_h
#define Ex61SelfSteeringVehicle_Vehicle_h

#include "cinder/gl/gl.h"

using namespace ci;

class Vehicle {

public:
    Vehicle() { }
    Vehicle( const float x, const float y )
    : position{ x, y },
      velocity{ Vec2f::zero() },
      acceleration{ Vec2f::zero() },
      r{ 16.f },
      maxForce{ 0.8f },
      maxSpeed{ 8.f },
      angle{ 0.f }
    { }
    
    void update( const Vec2f& mousePosition );
    void draw() const;

private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    float angle;
    
    void applyForce( const Vec2f& force );
    void arrive( const Vec2f& target );

};

#endif
