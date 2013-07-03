//
//  Particle.cpp
//  Ex41SingleParticle
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "Particle.h"

void Particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 1.0/(256/2);
}

void Particle::display() {
    gl::color(1, 1, 1, lifespan);
    gl::drawSolidCircle(location, 8);
}

bool Particle::isDead() {
    if( lifespan < 0.0 ) {
        return true;
    }
    return false;
}