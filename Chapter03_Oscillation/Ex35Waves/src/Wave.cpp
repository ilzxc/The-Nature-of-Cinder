//
//  Wave.cpp
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#include "Wave.h"

void Wave::update() {
    for ( auto& c : circles ) {
        c.update();
    }
}

void Wave::draw() {
    
    window.bindFramebuffer();
    gl::clear( Color(0, 0, 0) );
    gl::color( 1.0f, 1.0f, 1.0f, 0.9f );
    for ( auto& c : circles ) {
        c.draw();
    }
    window.unbindFramebuffer();
    
    gl::pushMatrices();
    gl::translate( windowPosition );
    gl::color( 0.01f, 0.01f, 0.01f );
    gl::drawSolidRect( window.getBounds() );
    gl::color( 1, 1, 1 );
    gl::draw( window.getTexture() );
    gl::popMatrices();
}