//
//  Particle.cpp
//  Ex57Collisions
//
//  Created by Ilya Rostovtsev on 7/24/13.
//
//

#include "Particle.h"

Particle::Particle( b2World *world, const Vec2f &_position, float _radius )
: position( _position ),
  radius( _radius ) {
    innerColor.set( 0.877f, 0.877f, 0.877f );
    b2BodyDef bd;
    bd.position = Conversions::toPhysics( position );
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
    body->SetUserData( this );
}

void Particle::update( b2World * world ) {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
    // std::cout << value << std::endl;
}

void Particle::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( 0.221, 0.221, 0.221 );
    gl::drawSolidCircle( Vec2f::zero(), radius, 16 );
    gl::color( innerColor );
    gl::drawSolidCircle( Vec2f::zero(), radius * 0.7f, 16 );
    gl::color( 0.221, 0.221, 0.221 );
    gl::drawSolidRect( Rectf(0, -2, radius, 2) );
    gl::popMatrices();
}

b2Body* Particle::getBody() const {
    return body;
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

void Particle::Touching() {
    innerColor.set( 0.877f, 0.0f, 0.0f );
}
void Particle::BeenTouched() {
    innerColor.set( 0.0f, 0.877f, 0.877f );

}