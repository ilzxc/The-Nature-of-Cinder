//
//  Boundary.cpp
//  Ex52FixedObjects
//
//  Created by Ilya Rostovtsev on 7/12/13.
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