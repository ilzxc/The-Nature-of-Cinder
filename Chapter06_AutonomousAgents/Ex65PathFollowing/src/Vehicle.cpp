#include "Vehicle.h"

Vehicle::Vehicle( const Vec2f& _position, float _maxForce, float _maxSpeed )
: position{ _position },
  velocity{ 1.f, 0.f },
  acceleration{ Vec2f::zero() },
  size{ 8.0f },
  maxForce{ _maxForce },
  maxSpeed{ _maxSpeed },
  angle{ 0.0f },
  triPoints{ Vec2f{ size * 2, 0.f }, Vec2f{ -size * 2, size }, Vec2f{ -size * 2, -size } }
{ }

void Vehicle::update( const Path& p )
{
    follow( p );
    velocity += acceleration;
    velocity.limit( maxSpeed );
    position += velocity;
    acceleration.set( Vec2f::zero() );
    angle = toDegrees( atan2f( velocity.y, velocity.x ) );
    borders( p );
}

void Vehicle::draw() const
{
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::drawSolidTriangle( &triPoints[ 0 ] );
    gl::popMatrices();
}

void Vehicle::follow( const Path& p )
{
    // predict location 70 frames ahead (arbitrary number):
    auto predict = velocity;
    predict.normalize();
    predict *= 70.0f;
    auto predictPosition = position + predict;

    Vec2f normal;
    Vec2f target;
    auto worldRecord = 1000000.f; // start with a very high record distance

    auto& pathPoints = p.getPoints();
    for( auto i = 0; i < pathPoints.size() - 1; ++i ) {
        auto a = pathPoints[ i ];
        auto b = pathPoints[ i + 1 ];

        auto normalPoint = getNormalPoint( predictPosition, a, b );
        // This only works because we know our path goes from left to right...
        if ( ( normalPoint.x < a.x ) || ( normalPoint.x > b.x ) ) {
            // a hacky solution - if it's not within the line segment, consider
            // the normal to just be the end of the line segment:
            normalPoint = b;
        }

        // How far away are we from the path?
        auto distance = predictPosition.distance( normalPoint );
        if ( distance < worldRecord ) {
            worldRecord = distance;
            normal = normalPoint;

            // look at the diretion of the line segment, seeking a little head of the normal:
            b -= a; // b becomes direction
            b.normalize();
            // simplified - should be based on distance to path & velocity:
            b *= 20.0f;
            target = normalPoint;
            target += b;
        }
    }

    if ( worldRecord > p.getRadius() ) {
        seek( target );
    }
}

void Vehicle::seek( const Vec2f& target )
{
    auto desired = target - position;
    if ( desired.length() == 0 ) return;
    desired.normalize();
    desired *= maxSpeed;
    desired -= velocity;        // steer
    desired.limit( maxForce );
    acceleration += desired;
}

Vec2f Vehicle::getNormalPoint( const Vec2f& p, const Vec2f& a, const Vec2f& b )
{
    auto ap = p - a;
    auto ab = b - a;
    ab.normalize();
    ab *= ( ap.dot( ab ) );
    return a + ab;
}

void Vehicle::borders( const Path& p )
{
    if ( position.x > p.getEnd().x + size ) {
      position.x = p.getStart().x - size;
      position.y = p.getStart().y + ( position.y - p.getEnd().y );
    }
}