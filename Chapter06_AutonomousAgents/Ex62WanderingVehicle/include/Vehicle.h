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
    
public:
    Vehicle( const Vec2f& _position )
    : position{ _position },
      velocity{ 1.f, 1.f },
      acceleration{ Vec2f::zero() },
      wanderTheta{ 0.f },
      size{ 16.f },
      maxForce{ 0.2f },
      maxSpeed{ 3.f },
      angle{ 0.f },
      debug{ false },
      circle{ Vec2f::zero() },
      target{ Vec2f::zero() },
      wanderR{ 45.f },
      wanderD{ 200.f },
      change{ 0.3f }
    {
        std::cout << velocity.x << ", " << velocity.y << std::endl;
    }
    
    void update();
    void draw() const;
    void toggleDebug();
        
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

};

#endif
