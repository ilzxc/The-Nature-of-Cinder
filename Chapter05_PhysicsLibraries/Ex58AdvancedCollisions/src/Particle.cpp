//
//  Particle.cpp
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 7/28/13.
//
//

#include "Particle.h"

void Particle::update( b2Body *body ) {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
}

void Particle::draw() const {}

void Particle::startDraw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( color.x, color.y, color.z );
}

void Particle::endDraw() const {
    gl::popMatrices();
}

void Particle::setForDeletion() {
    isDead = true;
}

bool Particle::checkIfDead() const {
    return isDead;
}

void Particle::setColor( const float r, const float g, const float b ) {
    color.set( r, g, b );
}