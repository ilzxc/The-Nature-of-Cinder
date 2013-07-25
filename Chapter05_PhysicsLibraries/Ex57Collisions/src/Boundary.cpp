//
//  Boundary.cpp
//  Ex57Collisions
//
//  Created by Ilya Rostovtsev on 7/24/13.
//
//

#include "Boundary.h"

void Boundary::draw() const {
    gl::color( 1, 1, 1 );
    gl::pushMatrices();
    gl::translate( position );
    gl::drawSolidRect( bounds );
    gl::popMatrices();
}