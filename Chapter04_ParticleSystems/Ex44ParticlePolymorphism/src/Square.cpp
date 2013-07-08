//
//  Square.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "Square.h"

void Square::update() {
    Rotational::update();
}

void Square::draw() const {
    Rotational::draw();
    gl::drawSolidRect( bounds );
}