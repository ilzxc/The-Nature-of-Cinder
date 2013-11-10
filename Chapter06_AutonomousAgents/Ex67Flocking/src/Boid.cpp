//
//  Boid.cpp
//  Ex67Flocking
//
//  Created by Ilya Rostovtsev on 9/17/13.
//
//

#include "Boid.h"

Boid::Boid( const Vec2f& _location )
: location{ _location },
  velocity(),
  acceleration{ Vec2f::zero() },
  r{ 4.f },
  maxForce{ 0.05f },
  maxSpeed{ 3.f },
  angle{ 0.f },
  triPoints{ Vec2f{ 0, -r * 2 }, Vec2f{ -r, r * 2 }, Vec2f{ r, r * 2 } }
{
    Rand::randomize();
    velocity = Vec2f{ Rand::randFloat( -1.f, 1.f ), Rand::randFloat( -1.f, 1.f ) };
}

void Boid::update( const vector< unique_ptr< Boid > >& boids )
{
    borders();
    flock( boids );
    velocity += acceleration;
    angle = toDegrees( atan2( velocity.y, velocity.x ) ) + 90.f;
    velocity.limit( maxSpeed );
    location += velocity;
    acceleration = Vec2f::zero();
}

void Boid::draw() const
{
    gl::pushMatrices();
    gl::translate( location );
    gl::rotate( angle );
    gl::color( Color::black() );
    gl::drawSolidTriangle( &triPoints[0] );
    gl::popMatrices();
}


const Vec2f& Boid::getLocation() const
{
    return location;
}

void Boid::applyForce( const Vec2f& force )
{
    acceleration += force;
}

void Boid::flock( const vector< unique_ptr< Boid > >& boids )
{
    Vec2f separation = separate( boids );
    Vec2f alignment = align( boids );
    Vec2f cohesion = cohere( boids );
    // Weigh these forces:
    separation *= 1.5f;
    alignment *= 1.1f;
    cohesion *= 0.9f;
    // Apply forces:
    applyForce( separation );
    applyForce( alignment );
    applyForce( cohesion );
}

Vec2f Boid::separate( const vector< unique_ptr< Boid > >& boids )
{
    auto desiredSeparation = r * 15;
    auto steer = Vec2f::zero();
    auto count = 0;
    
    for ( auto& other : boids )
    {
        auto d = location.distance( other->getLocation() );
        if ( ( d > 0 ) && ( d < desiredSeparation ) ) {
            auto diff = location - other->getLocation();
            diff.normalize();
            diff /= d;
            steer += diff;
            ++count;
        }
    }
    
    if ( count > 0 ) {
        steer /= static_cast< float >( count );
    }
    
    if ( steer.length() > 0 ) {
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit( maxForce );
    }
    
    return steer;
}

Vec2f Boid::align( const vector< unique_ptr< Boid > >& boids )
{
    auto neighborDistance = 50.f;
    auto sum = Vec2f::zero();
    auto count = 0;
    
    for ( auto& boid : boids )
    {
        auto d = location.distance( boid->getLocation() );
        if ( ( d > 0 ) && ( d < neighborDistance ) ) {
            sum += boid->velocity;
            ++count;
        }
    }
    
    if ( count > 0 ) {
        sum /= static_cast< float >( count );
        sum.normalize();
        sum *= maxSpeed;
        auto steer = sum - velocity;
        steer.limit( maxForce );
        return steer;
    }
    
    return Vec2f::zero();
}

Vec2f Boid::cohere( const vector< unique_ptr< Boid > >& boids )
{
    auto neighborDistance = 50.f;
    auto sum = Vec2f::zero();
    int count = 0;
    
    for ( auto& other : boids )
    {
        auto d = location.distance( other->getLocation() );
        if ( ( d > 0 ) && ( d < neighborDistance ) ) {
            sum += other->getLocation();
            ++count;
        }
    }
    
    if ( count > 0 ) {
        sum /= static_cast< float >( count );
        return seek( sum );
    }

    return Vec2f::zero();
}

Vec2f Boid::seek( const Vec2f& target ) const
{
    Vec2f desired = target - location;
    desired.normalize();
    desired *= maxSpeed;
    Vec2f steer = desired - velocity;
    steer.limit( maxForce );
    return steer;
}

void Boid::borders()
{
    if ( location.x < -r ) { location.x = app::getWindowWidth() + r; }
    if ( location.y < -r ) { location.y = app::getWindowHeight() + r; }
    if ( location.x > app::getWindowWidth() + r ) { location.x = -r; }
    if ( location.y > app::getWindowHeight() + r ) { location.y = -r; }
}
