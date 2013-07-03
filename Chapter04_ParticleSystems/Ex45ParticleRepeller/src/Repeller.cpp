//
//  Repeller.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "Repeller.h"

void Repeller::draw() {
    gl::pushMatrices();
    gl::translate(location);
    gl::color(30.0/255, 95.0/255, 153.0/255);
    gl::drawSolidCircle(Vec2f(0, 0), radius);
    gl::color(102.0/255, 156.0/255, 204.0/255);
    gl::drawStrokedCircle(Vec2f(0, 0), radius * 0.80f);
    gl::popMatrices();
}

const Vec2f Repeller::repel( Particle& p ) {
    Vec2f direction = location - p.getPosition();
    float d = direction.length();
    direction.normalize();
    if (d < 15.0f) {
        d = 15.0f;
    } else if (d > radius * 2) {
        d = radius * 2;
    }
    float force = -1.0f * strength / ( d * d );
    direction *= force;
    return direction;
}

void Repeller::setLocation( Vec2i mouse ) {
    location = mouse;
}