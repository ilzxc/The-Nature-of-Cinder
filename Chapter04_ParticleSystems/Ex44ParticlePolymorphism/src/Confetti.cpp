//
//  Confetti.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "Confetti.h"

void Confetti::update() {
    Particle::update();
    rotation += rotationSpeed;
}

void Confetti::draw() {
    gl::color(color.x, color.y, color.z, lifespan);
    gl::pushMatrices();
    gl::translate(position);
    gl::rotate(rotation);
    gl::drawSolidRect( Rectf(-sizeRadius, -sizeRadius, sizeRadius, sizeRadius) );
    gl::popMatrices();
}