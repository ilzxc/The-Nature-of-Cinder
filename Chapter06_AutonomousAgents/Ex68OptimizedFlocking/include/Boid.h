//
//  Boid.h
//  Ex68OptimizedFlocking
//
//  Created by Ilya Rostovtsev on 11/9/13.
//
//

#ifndef Ex68OptimizedFlocking_Boid_h
#define Ex68OptimizedFlocking_Boid_h

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

using namespace ci;
using namespace std;

class Boid
{
    
public:
    Boid( const Rand& random, const int team );
    ~Boid();
    void updateLocation();
    void update( const vector< shared_ptr< Boid > >& boids );
    void draw() const;
    const Vec2f& getLocation() const;
    const Vec2f& getVelocity() const;
    
private:
    Vec2f location;
    Vec2f nextFrame;
    Vec2f velocity;
    Vec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    float angle;
    float neighborDistance;
    ColorA color;
    std::vector< Vec2f > triPoints;
    
    void flock( const vector< shared_ptr< Boid > >& boids );
    const Vec2f separate( const vector< shared_ptr< Boid > >& boids );
    const Vec2f align( const vector< shared_ptr< Boid > >& boids );
    const Vec2f cohere( const vector< shared_ptr< Boid > >& boids );
    const Vec2f seek( const Vec2f& target ) const;
    void borders();
    void applyForce( const Vec2f& force );
};

#endif