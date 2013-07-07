//
//  Attractor.cpp
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#include "Attractor.h"

Vec2f Attractor::attract( Mover& m ){
    Vec2f force = location - m.getLocation();
    float d = force.length();
    d = 
}


void Attractor::draw();
void Attractor::clicked( int mx, int my );
void Attractor::hover( int mx, int my );
void Attractor::stopDragging();
void Attractor::drag();