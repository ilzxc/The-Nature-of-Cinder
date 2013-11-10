//
//  Vehicle.cpp
//  Ex66GroupBehaviors
//
//  Created by Ilya Rostovtsev on 11/8/13.
//
//

#include "Vehicle.h"

Vehicle::Vehicle( const Vec2f& loc, const float ms, const float mf )
: location{ loc },
  maxSpeed{ ms },
  maxForce{ mf },
  acceleration{ Vec2f::zero() },
  velocity{ maxSpeed, 0.f },
  r{ 7.f }
{ }

void Vehicle::update( const std::vector< Vehicle >& vehicles, const Path& path )
{
    applyBehaviors( vehicles, path );
    velocity += acceleration;
    velocity.limit( maxSpeed );
    location += velocity;
    acceleration = Vec2f::zero();
    borders();
}

void Vehicle::draw() const
{
    gl::color( 75.f / 255, 75.f / 255, 75.f / 255 );
    gl::pushMatrices();
    gl::translate( location );
    gl::drawSolidCircle( Vec2f::zero(), r );
    gl::popMatrices();
}

const Vec2f& Vehicle::getLocation() const
{
    return location;
}

void Vehicle::applyBehaviors( const std::vector< Vehicle >& vehicles, const Path& path )
{
    auto f = follow( path );
    auto s = separate( vehicles );
    
    f *= 3.f;
    s *= 1.f;
    
    applyForce( f );
    applyForce( s );
}

void Vehicle::applyForce( const Vec2f& force )
{
    acceleration += force;
}

Vec2f Vehicle::follow( const Path& path ) const
{
    auto predict = velocity;
    predict.normalize();
    predict *= 50.f;
    auto predictLocation = predict + location;
    auto worldRecord = 1000000.f;
    Vec2f target;
    
    auto& pathPoints = path.getPoints();
    for ( auto i = 0; i < pathPoints.size(); ++i ) {
        auto& a = pathPoints[ i ];
        auto& b = pathPoints[ ( i + 1 ) % pathPoints.size() ];
        auto normalPoint = getNormalPoint( predictLocation, a, b );
        auto dir = b - a;
        if ( ( normalPoint.x < std::min( a.x, b.x ) ) || ( normalPoint.x > std::max( a.x, b.x ) ) || ( normalPoint.y < std::min( a.y, b.y ) ) || ( normalPoint.y > std::max( a.y, b.y ) ) ) {
            normalPoint = b;
            // Check for endpoints:
            auto& a1 = pathPoints[ ( i + 1 ) % pathPoints.size() ];
            auto& b1 = pathPoints[ ( i + 2 ) % pathPoints.size() ];
            dir = b1 - a1;
        }
        // How far away are we from the path?
        auto d = predictLocation.distance( normalPoint );
        if ( d < worldRecord ) {
            worldRecord = d;
            auto normal = normalPoint;
            dir.normalize();
            dir *= 25.f;
            target = normal;
            target += dir;
        }
    }
    
    if ( worldRecord > path.getRadius() ) {
        return seek( target );
    }
    return Vec2f::zero();
}

Vec2f Vehicle::separate( const std::vector< Vehicle >& vehicles ) const
{
    auto desiredSeparation = r * 2;
    auto steer = Vec2f::zero();
    auto count = 0.f;
    
    for ( int i = 0; i < vehicles.size(); ++i ) {
        auto& other = vehicles[ i ];
        auto d = location.distance( other.getLocation() );
        if ( ( d > 0 ) && ( d < desiredSeparation ) ) {
            auto diff = location - other.getLocation();
            diff.normalize();
            diff /= d;
            steer += diff;
            ++count;
        }
    }
    // Average:
    if ( count > 0 ) {
        steer /= count;
    }
    // As long as the vector is greater than 0:
    if ( steer.length() > 0 ) {
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit( maxForce );
    }
    return steer;
}

Vec2f Vehicle::getNormalPoint( const Vec2f& p, const Vec2f& a, const Vec2f b ) const
{
    auto ap = p - a;
    auto ab = b - a;
    ab.normalize();
    ab *= ( ap.dot( ab ) );
    return a + ab; // normal point;
}

Vec2f Vehicle::seek( const Vec2f& target ) const
{
    auto desired = target - location;
    if (desired.length() == 0) return Vec2f::zero();
    desired.normalize();
    desired *= maxSpeed;
    auto steer = desired - velocity;
    steer.limit( maxForce );
    return steer;
}

void Vehicle::borders()
{
    if ( location.x < -r ) location.x = app::getWindowWidth() + r;
    if ( location.x > app::getWindowWidth() + r ) location.x = -r;
}

