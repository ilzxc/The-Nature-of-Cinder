//
//  Mover.cpp
//  Ex21Wind
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#include "Mover.h"

void Mover::applyForce( const Vec2f& force ) {
    Vec2f f = force / mass;
    acceleration += f;
}

void Mover::update() {
    velocity += acceleration;
    location += velocity;
    checkEdges();
    acceleration = Vec2f::zero();
}

void Mover::draw() {
    gl::color( 127.0f, 127.0f, 127.0f );
    gl::drawSolidCircle( location, radius );
}

void Mover::checkEdges() {
    if (location.x > app::getWindowWidth() - radius) {
        location.x = app::getWindowWidth() - radius;
        velocity.x *= -1;
    } else if (location.x < radius) {
        location.x = radius;
        velocity.x *= -1;
    }
    
    if (location.y > app::getWindowHeight() - radius) {
        location.y = app::getWindowHeight() - radius;
        velocity.y *= -1;
    }
}