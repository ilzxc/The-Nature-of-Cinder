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
    Particle::draw( rotation, square );
}

