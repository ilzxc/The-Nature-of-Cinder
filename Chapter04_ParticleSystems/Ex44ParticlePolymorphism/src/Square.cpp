//
//  Square.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#include "Square.h"

Square::Square( const float side, const float initialAngle, const float rotationSpeed )
: Rotational( initialAngle, rotationSpeed ),
  bounds( -side, -side, side, side ),
  Shape::Shape( 54.0f / 255, 33.0f / 255, 68.0f / 255 )
{ }

void Square::update() {
    Rotational::update();
}

void Square::draw() const {
    Rotational::draw();
    gl::drawSolidRect( bounds );
}