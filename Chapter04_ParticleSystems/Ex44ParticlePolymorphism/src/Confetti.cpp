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
    shape->update();
}

void Confetti::draw() {
    Particle::draw( *shape );
}

