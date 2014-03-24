//
//  Vehicle.cpp
//  Ex102SeekingNeural
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#include "Vehicle.h"

Vehicle::Vehicle( const int n, const float x, const float y, shared_ptr< Rand > random )
: brain( n, 0.001, random ),
  location( x, y ),
  velocity( Vec2f::zero() ),
  acceleration( Vec2f::zero() ),
  r( 3.f ),
  maxforce( 0.1f ),
  maxspeed( 4.f ),
  desired( app::getWindowCenter() )
{

}

void Vehicle::update()
{
    velocity += acceleration;
    velocity.limit( maxspeed );
    location += velocity;
    acceleration *= 0.f;
    location.x = constrain( location.x, 0.f, static_cast< float >( app::getWindowWidth() ) );
    location.y = constrain( location.y, 0.f, static_cast< float >( app::getWindowHeight() ) );
    theta = toDegrees( atan2f( velocity.y, velocity.x ) ) + 90;
}

void Vehicle::draw() const
{
    gl::color( 0.f, 0.f, 0.686f );
    gl::pushMatrices();
    gl::translate( location );
    gl::rotate( theta );
    gl::drawSolidTriangle( Vec2f( 0, -r * 2 ), Vec2f( -r, r * 2 ), Vec2f( r, r * 2 ) );
    gl::popMatrices();
}

void Vehicle::applyForce( const Vec2f& force )
{
    acceleration += force;
}

void Vehicle::steer( const vector< Vec2f >& targets )
{
    vector< Vec2f > forces;
    for ( auto i = 0; i < targets.size(); ++i ) {
        forces.push_back( seek( targets[ i ] ) );
    }
    Vec2f result = brain.feedforward( forces );
    applyForce( result );
    Vec2f error = desired - location;
    brain.train( forces, error );
}

Vec2f Vehicle::seek( const Vec2f& target )
{
    Vec2f desire = target - location;
    desire.normalize();
    desire *= maxspeed;
    Vec2f steer = desire - velocity;
    steer.limit( maxforce );
    return steer;
}
