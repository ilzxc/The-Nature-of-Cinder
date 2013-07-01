//
//  square.cpp
//  oscar
//
//  Created by Ilya Rostovtsev on 5/14/13.
//
//

#include "square.h"

square::square() {
    color.set(255, 255, 255);
}

void square::update( float angle ) {
    rotation = angle;
}

void square::update( cinder::Vec3f pigment ) {
    color = pigment;
}

void square::draw() {
    cinder::gl::pushMatrices();
    cinder::gl::translate( cinder::app::getWindowCenter() );
    cinder::gl::rotate(rotation);
    cinder::gl::color(color.x, color.y, color.z);
    cinder::Rectf theSquare(-50.0f, -50.0f, 50.0f, 50.0f);
    cinder::gl::drawSolidRect( theSquare );
    cinder::gl::popMatrices();
}