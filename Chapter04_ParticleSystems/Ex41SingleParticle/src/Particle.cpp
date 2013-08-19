//
//  Particle.cpp
//  Ex41SingleParticle
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/17/13
//

#include "Particle.h"

Particle::Particle( const Vec2f& location_, const Vec2f& acceleration_ ) :
    location( location_ ),
    velocity( 0.0f, 0.05f ),
    acceleration( acceleration_ ),
    lifespan( 1.0f ) {
}

void Particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 1.0 / 128;
}

void Particle::draw() const {
    gl::color( 1.0f, 1.0f, 1.0f, lifespan );
    gl::drawSolidCircle( location, 8.0f );
}

bool Particle::isDead() const {
    if( lifespan < 0.0f ) {
        return true;
    }
    return false;
}