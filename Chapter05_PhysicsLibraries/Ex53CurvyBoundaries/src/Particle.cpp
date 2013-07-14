//
//  Particle.cpp
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/13/13.
//
//

#include "Particle.h"

void Particle::makeBody( b2World * world ){
    b2BodyDef bd;
    bd.position = Conversions::toPhysics( position );
    bd.angle = toRadians( angle );
    bd.type = b2_dynamicBody;
    body = world->CreateBody( &bd );
    
    b2CircleShape cs;
    cs.m_radius = Conversions::toPhysics( radius );
    b2FixtureDef fd;
    fd.shape = &cs;
    fd.density = 1.0f;
    fd.friction = 0.03f;
    fd.restitution = 0.3f;
    
    body->CreateFixture( &fd );
    
}

void Particle::update( b2World * world ) {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
}

void Particle::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( 0.221, 0.221, 0.221 );
    gl::drawSolidCircle( Vec2f::zero(), radius, 16 );
    gl::color( 0.721, 0.721, 0.721 );
    gl::drawSolidCircle( Vec2f::zero(), radius * 0.7f, 16 );
    gl::color( 0.221, 0.221, 0.221 );
    gl::drawSolidRect( Rectf(0, -2, radius, 2) );
    gl::popMatrices();
}

void Particle::killBody( b2World * world ) {
    world->DestroyBody( body );
}

bool Particle::isDead() const {
    if ( position.y > app::getWindowHeight() + (radius * 2) ) {
        return true;
    }
    return false;
}