//
//  Attractor.cpp
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 5/24/13.
//
//

#include "Attractor.h"

void Attractor::setLocation( ci::Vec2f const& newLoc ){
    location = newLoc;
}

ci::Vec2f Attractor::attract(Mover const& m) {
    ci::Vec2f force = location - m.location;
    float d = force.length();
    
    if (d < 5.0) { d = 5.0; }
    else if (d > 25.0) { d = 25.0; }
    
    force.normalize();
    float strength = (G * mass * m.mass) / (d * d);
    force *= strength;
    
    return force;
}

void Attractor::draw() {
    if(dragging) { ci::gl::color(50.0/255, 50.0/255, 50.0/255); }
    else if (rollover) { ci::gl::color(100.0/255, 100.0/255, 100.0/255); }
    else { ci::gl::color(175.0/255, 175.0/255, 175.0/255); }
    ci::gl::drawSolidCircle(location, mass * 2);
}

void Attractor::clicked( ci::Vec2f const& mouse ) {
    float d = mouse.distance(location);
    if (d < mass) {
        dragging = true;
        dragOffset.set(location - mouse);
    }
}

void Attractor::hover( ci::Vec2f const& mouse ) {
    float d = mouse.distance(location);
    rollover = (d < mass) ? true : false;
}

void Attractor::stopDragging() {
    dragging = false;
}

void Attractor::drag( ci::Vec2f const& mouse ) {
    if (dragging) {
        location += (dragOffset + mouse);
    }
}