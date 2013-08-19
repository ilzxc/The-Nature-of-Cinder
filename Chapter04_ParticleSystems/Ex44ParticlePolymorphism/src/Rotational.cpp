//
//  Rotational.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#include "Rotational.h"

Rotational::Rotational( const float rotation_, const float rotationSpeed_ )
: rotation( rotation_ ),
  rotationSpeed( rotationSpeed_ )
{ }

void Rotational::update() {
    rotation += rotationSpeed;
}

void Rotational::draw() const {
    gl::rotate( rotation );
}