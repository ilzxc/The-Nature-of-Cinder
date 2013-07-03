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

void Particle::draw() {
    gl::color(color.x, color.y, color.z, lifespan);
    gl::pushMatrices();
    gl::translate(position);
    gl::drawSolidCircle(Vec2f(0.0f, 0.0f), sizeRadius);
    gl::popMatrices();
}

bool Particle::isDead() {
    if(lifespan < 0.0f) {
        return true;
    }
    return false;
}

void Particle::setColor(Vec3f newColor) {
    color = newColor;
}