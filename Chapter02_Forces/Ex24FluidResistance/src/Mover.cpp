//
//  Mover.cpp
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 5/20/13.
//
//

#include "Mover.h"

void Mover::applyForce(ci::Vec2f const& force){
    ci::Vec2f f = force / mass;
    acceleration += f;
}

void Mover::update() {
    velocity += acceleration;
    location += velocity;
    acceleration.set(0.0f, 0.0f);
}

void Mover::draw(){
    ci::gl::color( 0, 55, 100, 0.7f );
    ci::gl::drawSolidCircle( location, mass );
}


void Mover::checkEdges() {
    if ( location.y > ci::app::getWindowHeight() ) {
        velocity.y *= -0.9f;
        location.y = ci::app::getWindowHeight();
    }
}