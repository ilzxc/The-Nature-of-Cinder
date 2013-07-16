#include "Vehicle.h"

void Vehicle::follow( const Path& p ) {
	// predict location 50 frames ahead (arbitrary number):
	Vec2f predict = velocity;
	predict.normalize();
	predict *= 70.0f;
	Vec2f predictPosition = position + predict;

	Vec2f normal;
	Vec2f target;
	float worldRecord = 1000000; // start with a very high record distance

	for( int i = 0; i < p.getPoints().size() - 1; ++i ) {
		Vec2f a = p.getPoints()[i];
		Vec2f b = p.getPoints()[i+1];

		Vec2f normalPoint = getNormalPoint( predictPosition, a, b );
		// This only works because we know our path goes from left to right...
		if (normalPoint.x < a.x || normalPoint.x > b.x) {
			// a hacky solution - if it's not within the line segment, consider
			// the normal to just be the end of the line segment:
			normalPoint = b;
		}

		// How far away are we from the path?
		float distance = predictPosition.distance( normalPoint );
		if (distance < worldRecord) {
			worldRecord = distance;
			normal = normalPoint;

			// look at the diretion of the line segment, seeking a little head of the normal:
			Vec2f dir = b - a;
			dir.normalize();
			// simplified - should be based on distance to path & velocity:
			dir *= 20.0f;
			target = normalPoint;
			target += dir;
		}
	}

	if (worldRecord > p.getRadius()) {
		seek( target );
	}
}

void Vehicle::seek( const Vec2f& target ) {
	Vec2f desired = target - position;

	if (desired.length() == 0) return;

	desired.normalize();
	desired *= maxSpeed;
	Vec2f steer = desired - velocity;
	steer.limit( maxForce );
	acceleration += steer;
}

Vec2f Vehicle::getNormalPoint( const Vec2f& p, const Vec2f& a, const Vec2f& b ) {
	Vec2f ap = p - a;
	Vec2f ab = b - a;
	ab.normalize();
	ab *= ( ap.dot( ab ) );
	Vec2f normalPoint = a + ab;
	return normalPoint;
}

void Vehicle::borders( const Path& p ) {
	if (position.x > p.getEnd().x + size) {
      position.x = p.getStart().x - size;
      position.y = p.getStart().y + ( position.y - p.getEnd().y );
    }
}

void Vehicle::update( const Path& p ) {
	follow( p );
	velocity += acceleration;
	velocity.limit( maxSpeed );
	position += velocity;
	acceleration.set( Vec2f::zero() );
	angle = toDegrees( atan2f( velocity.y, velocity.x ) );
	borders( p );
}

void Vehicle::draw() const {
	gl::pushMatrices();
	gl::translate( position );
	gl::rotate( angle );
    gl::color( 0.222f, 0.222f, 0.222f );
	gl::drawSolidTriangle( Vec2f(size*2, 0), Vec2f(-size*2, size), Vec2f(-size*2, -size) );
	gl::popMatrices();
}