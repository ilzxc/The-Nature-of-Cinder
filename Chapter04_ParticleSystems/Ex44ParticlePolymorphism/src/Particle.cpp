//
//  Particle.cpp
//  Ex44ParticlePolymorphism
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

void Particle::draw( const Shape& shape ) const {
    gl::pushMatrices();
    gl::translate(position);
    gl::color(shape.color.x, shape.color.y, shape.color.z, lifespan);
    shape.draw();
    gl::popMatrices();
}

bool Particle::isDead() {
    if(lifespan < 0.0f) {
        return true;
    }
    return false;
}

float Particle::getRadius() const {
    return sizeRadius;
}

float Particle::getLifespan() const {
    return lifespan;
}