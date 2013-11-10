//
//  Particle.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "Particle.h"

Vec2f Particle::getPosition() const {
    return Vec2f(position);
}

void Particle::update() {
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
    rotation += rotationSpeed;
}

void Particle::applyForce( const Vec2f& force ) {
    acceleration += force;
}

void Particle::draw() {
    gl::pushMatrices();
    gl::translate(position);
    gl::rotate(rotation);
    gl::color(204.0f/255, 33.0f/255, 25.0f/255, lifespan);
    gl::drawSolidRect( Rectf(-sizeRadius, -sizeRadius, sizeRadius, sizeRadius) );
    gl::color( 1.0f, 1.0f, 1.0f, lifespan );
    gl::drawSolidRect( Rectf( -sizeRadius / 2.0f, -sizeRadius / 2.0f, sizeRadius / 2.0f, sizeRadius / 2.0f ) );
    gl::popMatrices();
}

bool Particle::isDead() {
    if( lifespan < 0.0f ) {
        return true;
    }
    return false;
}