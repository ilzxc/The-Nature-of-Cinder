//
//  Rotational.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "Rotational.h"

void Rotational::update() {
    rotation += rotationSpeed;
}

void Rotational::draw() const {
    gl::rotate( rotation );
}