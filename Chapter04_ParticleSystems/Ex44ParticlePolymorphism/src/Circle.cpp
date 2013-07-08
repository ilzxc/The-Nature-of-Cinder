//
//  Circle.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "Circle.h"

void Circle::update() {
}

void Circle::draw() const {
    gl::drawSolidCircle( Vec2f::zero(), radius );
}