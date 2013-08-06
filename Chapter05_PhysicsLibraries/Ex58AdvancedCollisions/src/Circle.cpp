//
//  Circle.cpp
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 8/6/13.
//
//

#include "Circle.h"

Circle::Circle( b2World *world, const Vec2f &position, float _angle, float _radius ): Particle::Particle( position, _angle ) {
    radius = _radius;
    
    b2BodyDef bd;
    bd.type = b2BodyType::b2_dynamicBody;
    bd.position = Conversions::toPhysics( position );
    bd.angle = toRadians( _angle );
    body = world->CreateBody( &bd );
    
    b2FixtureDef fd;
    b2CircleShape cs;
    cs.m_radius = Conversions::toPhysics( radius );;
    fd.shape = &cs;
    fd.density = 1.0f;
    fd.friction = 0.04f;
    body->CreateFixture( &fd );
    body->SetAngularVelocity( 10.0f );
    body->SetUserData( new ObjectType( CIRCLE_PARTICLE, this ) );
}

void Circle::update() {
    Particle::update( body );
}

void Circle::draw() const {
    Particle::startDraw();
    gl::drawSolidCircle( Vec2f::zero(), radius );
    Particle::endDraw();
}

void Circle::killBody( b2World *world ) {
    world->DestroyBody( body );
}

bool Circle::isDead() const {
    return Particle::checkIfDead();
}

void Circle::onCollisionWith( const int otherObjectKind ) {
    switch ( otherObjectKind ) {
        case SQUARE_PARTICLE:
            Particle::setColor( 154.0f / 255, 40.0f / 255, 47.0f / 255 );
            break;
        case TRIANGLE_PARTICLE:
            // do something else
            break;
    }
}