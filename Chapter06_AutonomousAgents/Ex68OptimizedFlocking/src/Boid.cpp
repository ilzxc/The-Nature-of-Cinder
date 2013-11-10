//
//  Boid.cpp
//  Ex68OptimizedFlocking
//
//  Created by Ilya Rostovtsev on 11/9/13.
//
//

#include "Boid.h"

Boid::Boid( const Vec2f& _location, const Rand& random )
: location{ _location },
  acceleration{ Vec2f::zero() },
  r{ 3.f },
  maxForce{ 0.05f },
  maxSpeed{ 1.1f },
  angle{ 0.f },
  triPoints{ Vec2f{ 0, -r * 2 }, Vec2f{ -r, r * 2 }, Vec2f{ r, r * 2 } },
  neighborDistance{ r * r * 15 * 15 }
{
    velocity = Vec2f{ random.randFloat( 0.f, 1.f ), random.randFloat( 0.f, 1.f ) };
}

void Boid::update( const vector< shared_ptr< Boid > >& boids )
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

const Vec2f& Boid::getVelocity() const
{
    return velocity;
}

void Boid::applyForce( const Vec2f& force )
{
    acceleration += force;
}

void Boid::flock( const vector< shared_ptr< Boid > >& boids )
{
    applyForce( separate( boids ) * 1.5f );
    applyForce( align( boids ) * 1.1f );
    applyForce( cohere( boids ) * 0.9f );
}

const Vec2f Boid::separate( const vector< shared_ptr< Boid > >& boids )
{
    auto steer = Vec2f::zero();
    auto count = 0;
    
    for ( auto& other : boids )
    {
        auto d = location.distanceSquared( other->getLocation() );
        if ( ( d > 0 ) && ( d < neighborDistance ) ) {
            auto diff = location - other->getLocation();
            diff.normalize();
            diff /= sqrt( d );
            steer += diff;
            ++count;
        }
    }
    if ( count > 0 ) {
        steer /= static_cast< float >( count );
    }
    
    if ( steer.length() > 0 )
    {
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit( maxForce );
    }
    return steer;
}

const Vec2f Boid::align( const vector< shared_ptr< Boid > >& boids )
{
    auto sum = Vec2f::zero();
    auto count = 0;
    
    for ( auto& boid : boids )
    {
        auto d = location.distanceSquared( boid->getLocation() );
        if ( ( d > 0 ) && ( d < neighborDistance ) ) {
            sum += boid->getVelocity();
            ++count;
        }
    }
    
    if ( count > 0 ) {
        sum /= static_cast< float >( count );
        sum.normalize();
        sum *= maxSpeed;
        sum -= velocity; // steer
        sum.limit( maxForce );
        return sum;
    }
    
    return Vec2f::zero();
}

const Vec2f Boid::cohere( const vector< shared_ptr< Boid > >& boids )
{
    auto sum = Vec2f::zero();
    int count = 0;
    
    for ( auto& other : boids )
    {
        auto d = location.distanceSquared( other->getLocation() );
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

const Vec2f Boid::seek( const Vec2f& target ) const
{
    auto desired = target - location;
    desired.normalize();
    desired *= maxSpeed;
    desired -= velocity;    // steer
    desired.limit( maxForce );
    return desired;
}

void Boid::borders()
{
    if ( location.x < -r ) { location.x = app::getWindowWidth() + r; }
    if ( location.y < -r ) { location.y = app::getWindowHeight() + r; }
    if ( location.x > app::getWindowWidth() + r ) { location.x = -r; }
    if ( location.y > app::getWindowHeight() + r ) { location.y = -r; }
}

