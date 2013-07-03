//
//  Particle.cpp
//  Ex46TexturedParticles
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "Particle.h"

void Particle::update(const Vec2f &force) {
    acceleration += force;
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
}

void Particle::draw() {
    gl::color(0, lifespan * lifespan / 5.0, lifespan * lifespan * lifespan, lifespan);
    gl::pushMatrices();
    gl::translate(position);
    gl::draw( *texture, Rectf(-sizeRadius, -sizeRadius, sizeRadius, sizeRadius) );
    gl::popMatrices();
}

bool Particle::isDead() {
    if(lifespan < 0.0f) {
        return true;
    }
    return false;
}