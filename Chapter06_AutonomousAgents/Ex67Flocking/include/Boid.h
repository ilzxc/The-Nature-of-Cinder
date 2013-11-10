//
//  Boid.h
//  Ex67Flocking
//
//  Created by Ilya Rostovtsev on 9/17/13.
//
//

#ifndef Ex67Flocking_Boid_h
#define Ex67Flocking_Boid_h

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

using namespace ci;
using namespace std;

class Boid
{

public:
    Boid( const Vec2f& _location );
    void update( const vector< unique_ptr< Boid > >& boids );
    void draw() const;
    const Vec2f& getLocation() const;
    
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    float angle;
    std::vector< Vec2f > triPoints;
    
    void flock( const vector< unique_ptr< Boid > >& boids );
    Vec2f separate( const vector< unique_ptr< Boid > >& boids );
    Vec2f align( const vector< unique_ptr< Boid > >& boids );
    Vec2f cohere( const vector< unique_ptr< Boid > >& boids );
    Vec2f seek( const Vec2f& target ) const;
    void borders();
    void applyForce( const Vec2f& force );
};

#endif
