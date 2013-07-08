//
//  Triangle.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#include "Triangle.h"

void Triangle::update() {
    Rotational::update();
}

void Triangle::draw() const {
    Rotational::draw();
    gl::drawSolidTriangle(p1, p2, p3);
}