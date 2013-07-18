//
//  Pair.cpp
//  Ex55Joints
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#include "Pair.h"

Pair::Pair( b2World *world, const Vec2f &_position ) {
    float distance = 20.0f;
    Vec2f left  = Vec2f( (_position.x + distance), _position.y );
    Vec2f right = Vec2f( (_position.x - distance), _position.y );
    pair[0] = Particle( world, left, 7.0f );
    pair[1] = Particle( world, right, 7.0f );
    
    b2DistanceJointDef djd;
    djd.Initialize( pair[0].getBody(), pair[1].getBody(), Conversions::toPhysics( left ), Conversions::toPhysics( right ) );
    djd.length = Conversions::toPhysics( distance );
    djd.frequencyHz = 3;
    djd.dampingRatio = 0.8f;
    world->CreateJoint( &djd );
}

void Pair::update() {
    pair[0].update();
    pair[1].update();
    lineStart.set( Conversions::toScreen( pair[0].getBody()->GetPosition() ) );
    lineEnd.set( Conversions::toScreen( pair[1].getBody()->GetPosition() ) );
}

void Pair::draw() const {
    gl::drawLine( lineStart, lineEnd );
    pair[0].draw();
    pair[1].draw();
}

bool Pair::isDead() const {
    if( pair[0].isDead() && pair[1].isDead() ) {
        return true;
    }
    return false;
}

void Pair::killBody( b2World *world ) {
    pair[0].killBody( world );
    pair[1].killBody( world );
}