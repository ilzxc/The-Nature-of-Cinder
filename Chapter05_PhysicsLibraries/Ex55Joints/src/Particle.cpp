//
//  Particle.cpp
//  Ex55Joints
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#include "Particle.h"

Particle::Particle( b2World *world, const Vec2f &_position, float _radius )
: position( _position ),
  radius( _radius ) {
      b2BodyDef bd;
      bd.position = Conversions::toPhysics( position );
      bd.type = b2BodyType::b2_dynamicBody;
      body = world->CreateBody( &bd );
      
      b2CircleShape cs;
      cs.m_radius = Conversions::toPhysics( radius );
      b2FixtureDef fd;
      fd.shape = &cs;
      fd.density = 1.0f;
      fd.friction = 0.01f;
      fd.restitution = 0.3f;
      
      body->CreateFixture( &fd );
      body->SetLinearVelocity( b2Vec2( Rand::randFloat(-1.0, 1.0f), Rand::randFloat( -5.0f, -2.0f ) ) );
      body->SetAngularVelocity( Rand::randFloat(-5.0, 5.0f) );
}

void Particle::update() {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );    
}

void Particle::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::drawSolidCircle( Vec2f::zero(), radius, 16 );
    gl::color( 0.888f, 0.888f, 0.888f );
    gl::drawSolidCircle( Vec2f::zero(), radius * 0.7f, 16 );
    gl::color( 0.222f, 0.222f, 0.222f );
    gl::drawSolidRect( Rectf(0, -2, radius, 2) );
    gl::popMatrices();
}

b2Body* Particle::getBody() const {
    return body;
}

bool Particle::isDead() const {
    if (position.y > app::getWindowHeight() + 50.0f) {
        return true;
    }
    return false;
}

void Particle::killBody( b2World *world ) {
    world->DestroyBody( body );
}