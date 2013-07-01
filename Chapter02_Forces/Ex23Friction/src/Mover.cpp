//
//  Mover.cpp
//  Ex23Friction
//
//  Created by Ilya Rostovtsev on 4/12/13.
//
//

#include "Mover.h"

// Public Methods:

Mover::Mover() {
    fatness = ci::randFloat(1.0, 15.0);
    position = ci::Vec2f( ci::randInt( ci::app::getWindowWidth() ), fatness );
    velocity = ci::Vec2f( 0.0f, 0.0f );
    acceleration = ci::Vec2f( 0.0f, 0.0f );
}

void Mover::setPosition( ci::Vec2f newPosition ) {
    position = newPosition;
}

void Mover::setup( ci::Vec2f inGravity, ci::Vec2f inWind, float inFriction) {
    gravity = inGravity;
    wind = inWind;
    frictionCoeff = inFriction;
}

void Mover::update() {
    applyForces();
    
    velocity += acceleration;
    position += velocity;
    checkEdges();
    
    acceleration *= 0.0f;
}

void Mover::draw() {
    ci::gl::drawSolidCircle( position, fatness );
}

// Private Methods:

void Mover::applyFriction() {
    friction = velocity;
    friction *= -1;
    friction.normalized();
    friction *= frictionCoeff;
}

void Mover::applyForces() {
    applyForce( wind, true );
    applyForce( gravity, false );
    
    applyFriction();
    applyForce( friction, false );
}

void Mover::applyForce( ci::Vec2f force, bool scaleByMass ){
    if (scaleByMass) {
        acceleration += (force / fatness);
    } else {
        acceleration += force;
    }
}

void Mover::checkEdges() {
    if (position.x > ci::app::getWindowWidth() - fatness) {
        position.x = ci::app::getWindowWidth() - fatness;
        velocity.x *= -1;
    } else if (position.x < fatness) {
        velocity.x *= -1;
        position.x = fatness;
    }
    
    if (position.y > ci::app::getWindowHeight() - fatness) {
        velocity.y *= -1;
        position.y = ci::app::getWindowHeight() - fatness;
    }
}

