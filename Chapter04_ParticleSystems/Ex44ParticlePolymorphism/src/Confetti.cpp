//
//  Confetti.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "Confetti.h"

void Confetti::update() {
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
    rotation += 0.03;
}

void Confetti::draw() {
    gl::color(color.x, color.y, color.z, lifespan);
    gl::pushMatrices();
    gl::translate(position);
    gl::rotate(rotation);
    gl::drawSolidRect( Rectf(-sizeRadius, -sizeRadius, sizeRadius, sizeRadius) );
    gl::popMatrices();
}