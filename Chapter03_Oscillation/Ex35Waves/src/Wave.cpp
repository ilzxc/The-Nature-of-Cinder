//
//  Wave.cpp
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#include "Wave.h"

Wave::Wave( const float width, const float height, const Vec2f& winPos, const int numCircles, const float angVel )
: window( width, height ),
  windowPosition( winPos ) {
    float startAngle = 0.0f;
    float setRadius = width / numCircles;
    float setSkip = width / (numCircles - 1);
    float setYOffset = height / 2.0f;
    float setAmplitude = setYOffset * 0.88f;
    for ( int i = 0; i < numCircles; ++i ) {
        circles.push_back( WaveComponent( Vec2f( setSkip * i, setYOffset ), setRadius, setAmplitude, startAngle + angVel * 2 * i, angVel / 2 ) );
    }
}

void Wave::update() {
    for ( auto& c : circles ) {
        c.update();
    }
    
    // draw to the FrameBufferObject:
    window.bindFramebuffer();
    gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    gl::color( 1.0f, 1.0f, 1.0f, 0.9f );
    for ( auto& c : circles ) {
        c.draw();
    }
    window.unbindFramebuffer();
}

void Wave::draw() {
    gl::pushMatrices();
    gl::translate( windowPosition );
    gl::color( 0.01f, 0.01f, 0.01f );
    gl::drawSolidRect( window.getBounds() );
    gl::color( 1.0f, 1.0f, 1.0f );
    gl::draw( window.getTexture() );
    gl::popMatrices();
}