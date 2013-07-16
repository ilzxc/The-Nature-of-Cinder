#include "Vehicle.h"

void Vehicle::borders() {
	if ( position.x < -size ) {
        position.x = app::getWindowWidth() + size;
    } else if ( position.x > app::getWindowWidth() + size ) {
        position.x = -size;
    }
    
    if ( position.y < -size ) {
        position.y = app::getWindowHeight() + size;
    } else if ( position.y > app::getWindowHeight() + size ) {
        position.y = -size;
    }
}

void Vehicle::update( const FlowField& flow ) {
	Vec2f desired = flow.lookup( position );
	desired *= maxSpeed;
	Vec2f steer = desired - velocity;
	steer.limit( maxForce );
	acceleration += steer;
	velocity += acceleration;
	velocity.limit(maxSpeed);
	position += velocity;
	acceleration.set( Vec2f::zero() );
	angle = toDegrees( atan2f( velocity.y, velocity.x ) );
	borders();
}

void Vehicle::draw() const {
	gl::pushMatrices();
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidTriangle( Vec2f(size*2, 0), Vec2f(-size*2, size), Vec2f(-size*2, -size) );
    gl::popMatrices();
}