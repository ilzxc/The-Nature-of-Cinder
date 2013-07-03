//
//  Particle.cpp
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "Particle.h"

void Particle::update() {
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
}

void Particle::draw() {
    gl::color(1, 1, 1, lifespan);
    gl::drawSolidCircle(position, sizeRadius);
}

bool Particle::isDead() {
    if(lifespan < 0.0f) {
        return true;
    }
    return false;
}
