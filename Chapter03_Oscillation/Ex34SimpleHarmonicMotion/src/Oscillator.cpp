//
//  Oscillator.cpp
//  Ex34SimpleHarmonicMotion
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#include "Oscillator.h"

Oscillator::Oscillator( Rand& r, const Vec2f& windowCenter )
    : angle( Vec2f::zero() ),
      velocity( r.randFloat( -0.05f, 0.05f ), r.randFloat( -0.05f, 0.05f ) ),
      amplitude( r.randFloat( windowCenter.x ), r.randFloat( windowCenter.y ) )
    { }

void Oscillator::update() {
    angle += velocity;
    display = Vec2f( sin( angle.x ) * amplitude.x, sin( angle.y ) * amplitude.y );
}

void Oscillator::draw() const {
    gl::pushMatrices();
    gl::color( 0.4f, 0.4f, 0.4f );
    gl::translate( app::getWindowCenter() );
    gl::drawLine( Vec2f::zero(), display );
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::drawSolidCircle( display, velocity.length() * 100.0f );
    gl::popMatrices();
}