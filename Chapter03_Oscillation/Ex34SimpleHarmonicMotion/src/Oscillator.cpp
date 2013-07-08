//
//  Oscillator.cpp
//  Ex34SimpleHarmonicMotion
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#include "Oscillator.h"

void Oscillator::update() {
    angle += velocity;
    display = Vec2f( sin(angle.x) * amplitude.x, sin(angle.y) * amplitude.y );
}

void Oscillator::draw() const {
    gl::pushMatrices();
    gl::color( 0.4f, 0.4f, 0.4f );
    gl::translate( app::getWindowCenter() );
    gl::drawLine( Vec2f::zero(), display );
    gl::color( 1, 1, 1 );
    gl::drawSolidCircle( display, velocity.length() * 100.0f );
    gl::popMatrices();
}