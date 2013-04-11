//
//  Mover.cpp
//  Ex1_4_VectorAccelConst
//
//  Created by Ilya Rostovtsev on 4/7/13.
//
//

#include "Mover.h"

using namespace ci;

Mover::Mover( float fat ){
    fatness = fat;
    position = Vec2f( 0.0f, 0.0f );
    velocity = Vec2f( 0.0f, 0.0f );
}

void Mover::resetPosition() {
    position = Vec2f( fatness, fatness );
    velocity *= 0.0f;
}

void Mover::setAccel( Vec2f mousePos ) {
    float maxAccel = 3.0f;
    acceleration = (mousePos - position).normalized() * (maxAccel - fatness);
}

void Mover::update() {
    applyForces();
    velocity += acceleration;
    position += velocity;
    checkEdges();
    acceleration *= 0.0f; // now resetting the acceleration every update loop;
}

void Mover::draw() {
    gl::color( 178, 178, 178, 1.0 );
    gl::drawSolidCircle( position, fatness );
    
    gl::drawLine( app::getWindowCenter(), app::getWindowCenter() + (windForce * 100) );
}

// Accessors:

void Mover::setWind( const ci::Vec2f windDirection, const float windMag ) {
    windDirection.normalized();
    windForce = ( windDirection * windMag );
}

void Mover::setGravity ( const ci::Vec2f gravDirection, const float gravMag ) {
    gravDirection.normalized();
    gravityForce = ( gravDirection * gravMag );
}

void Mover::applyForces() {
    applyForce( windForce );
    applyForce( gravityForce );
    // acceleration += gravityForce;
}

// private functions:

void Mover::applyForce( const ci::Vec2f force ) {
    acceleration += (force / fatness);
}

void Mover::checkEdges() {
    if ( position.x > app::getWindowWidth() - fatness ) {
        velocity.x *= scaledDirections;
        position.x = app::getWindowWidth() - fatness;
    } else if ( position.x < fatness ) {
        velocity.x *= scaledDirections;
        position.x = fatness;
    }
    
    if ( position.y > ( app::getWindowHeight() - fatness ) ) {
        velocity.y *= scaledDirections;
        position.y = app::getWindowHeight() - fatness;
    } else if ( position.y < fatness ) {
        velocity.y *= scaledDirections;
        velocity.y = fatness;
    }
}