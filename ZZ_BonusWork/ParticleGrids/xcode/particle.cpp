//
//  particle.cpp
//  ParticleGrids
//
//  Created by Ilya Rostovtsev on 4/11/13.
//
//

#include "particle.h"

particle::particle( ci::Vec2f setPosition, float setSize, ci::Color setColor ){
    position = setPosition;
    size = setSize;
    color = setColor;
}

void particle::update( const ci::Vec2f newPosition ){
    position = newPosition;
}

void particle::update( const float newSize ){
    size = newSize;
}

void particle::update( const ci::Color newColor ){
    color = newColor;
}

void particle::draw() {
    ci::gl::color( color );
    ci::gl::drawSolidCircle( position, size );    
}