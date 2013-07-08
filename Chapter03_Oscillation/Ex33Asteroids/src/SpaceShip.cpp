//
//  SpaceShip.cpp
//  Ex33Asteroids
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "SpaceShip.h"

void SpaceShip::update( const bool keys[] ) {
    if ( keys[2] == true ) {
        thrusting = true;
    } else {
        thrusting = false;
    }
    
    if ( !( keys[0] && keys[1] ) ) {
        if ( keys[0] ) {
            heading -= 2;
        } else if ( keys[1] ) {
            heading += 2;
        }
    }
    
    if (thrusting) {
        float angle = toRadians(heading) - M_PI_2;
        Vec2f force = Vec2f( cos(angle), sin(angle) );
        force *= 0.1f;
        acceleration += force;
    }
    
    velocity += acceleration;
    velocity *= damping;
    velocity.limit(topspeed);
    position += velocity;
    acceleration = Vec2f::zero();
    
    wrapEdges();
}

void SpaceShip::wrapEdges() {
    float buffer = r * 2;
    if (position.x > app::getWindowWidth() +  buffer) {
        position.x = -buffer;
    } else if (position.x < -buffer) {
        position.x = app::getWindowWidth() + buffer;
    }
    
    if (position.y > app::getWindowHeight() + buffer) {
        position.y = -buffer;
    } else if (position.y < -buffer) {
        position.y = app::getWindowHeight() + buffer;
    }
}

void SpaceShip::draw(){
    gl::pushMatrices();
    gl::color(1, 1, 1);
    gl::translate(position.x, position.y + r);
    gl::rotate(heading);
    gl::drawSolidTriangle( Vec2f(0.0f, (-2 * r) ), Vec2f(r, r), Vec2f(-r, r) );
    if(thrusting) {
        gl::color(1, 0.6, 0);
    }
    gl::drawSolidRect( Rectf( -r, r, -r / 2, r + 3) );
    gl::drawSolidRect( Rectf( r/2, r, r, r + 3) );
    gl::popMatrices();
}