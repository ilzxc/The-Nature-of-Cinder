//
//  Liquid.cpp
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 5/20/13.
//
//

#include "Liquid.h"

bool Liquid::contains(Mover const& m) {
    ci::Vec2f l = m.location;
    if ( dimensions.contains( l ) ) {
        return true;
    }
    
    return false;
}

ci::Vec2f Liquid::drag(Mover const& m) {
    // magniture = coefficient * speed squared
    float speed = m.velocity.length();
    float dragMagnitude = c * speed * speed;
    
    // direction is inverse of velocity
    ci::Vec2f dragForce(m.velocity);
    dragForce *= -1;
    
    // scale according to magnitude
    dragForce.normalize();
    dragForce *= dragMagnitude;
    return dragForce;
}

void Liquid::draw() {
    ci::gl::color( 50.0f, 50.0f, 50.0f, 0.5f );
    ci::gl::drawSolidRect( dimensions );
}

void Liquid::setBounds() {
    dimensions.set(0, ci::app::getWindowHeight() / 2, ci::app::getWindowWidth(), ci::app::getWindowHeight());
}

