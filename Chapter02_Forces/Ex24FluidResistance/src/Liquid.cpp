//
//  Liquid.cpp
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#include "Liquid.h"

bool Liquid::contains( Mover& m ) {
    Vec2f l = m.getLocation();
    if ( (l.x > bounds.x1) && (l.x < bounds.x2) && (l.y > bounds.y1) && (l.y < bounds.y2) ) {
        return true;
    }
    return false;
}

Vec2f Liquid::drag( Mover& m ) {
    
    float speed = ( m.getVelocity() ).length();
    float dragMagnitude = c * speed * speed;
    Vec2f dragForce = m.getVelocity();
    if (dragForce != Vec2f::zero()) {
        dragForce *= -1.0f;
        dragForce.normalize();
        dragForce *= dragMagnitude;
    }
    
    return dragForce;
}

void Liquid::draw() {
    gl::color( 0.4f, 0.3f, 0.6f, 0.4f );
    gl::drawSolidRect( bounds );
}