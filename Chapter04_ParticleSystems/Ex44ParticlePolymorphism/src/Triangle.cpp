//
//  Triangle.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/19/13
//

#include "Triangle.h"

Triangle::Triangle( const float radius, const float initialAngle, const float rotationSpeed )
: Rotational( initialAngle, rotationSpeed ),
  p1( 0.0f, -radius ),
  p2( radius, radius ),
  p3( -radius, radius ),
  Shape( 218.0f / 255, 52.0f / 255, 48.0f / 255 )
{ }

void Triangle::update() {
    Rotational::update();
}

void Triangle::draw() const {
    Rotational::draw();
    gl::drawSolidTriangle( p1, p2, p3 );
}