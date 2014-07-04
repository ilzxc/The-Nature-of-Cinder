//
//  Circle.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#include "Circle.h"

Circle::Circle( const float radius_ )
: radius( radius_ ),
  Shape( 154.0f / 255, 40.0f / 255, 47.0f / 255 )
{ }

void Circle::update() {
}

void Circle::draw() const {
    gl::drawSolidCircle( Vec2f::zero(), radius );
}