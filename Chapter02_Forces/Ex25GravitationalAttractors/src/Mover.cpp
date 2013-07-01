//
//  Mover.cpp
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 5/24/13.
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
    acceleration *= 0.0f;
}

void Mover::draw() {
    ci::gl::color(0.5, 0.5, 0.5);
    ci::gl::drawSolidCircle(location, 16);
}

void Mover::checkEdges() {
    if (location.x > ci::app::getWindowWidth()) {
        location.x = 0;
    } else if (location.x < 0) {
        location.x = ci::app::getWindowWidth();
    }
    
    if (location.y > ci::app::getWindowHeight()) {
        velocity.y *= -1;
        location.y = ci::app::getWindowHeight();
    }
}