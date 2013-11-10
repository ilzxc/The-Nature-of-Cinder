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
    
public:
    Vehicle( const Vec2f& _position, const float _maxforce, const float _maxspeed );
    
    void update( const FlowField& flow );
    void draw() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    const float size;
    const float maxForce;
    const float maxSpeed;
    float angle;
    
	void borders();

};

#endif
