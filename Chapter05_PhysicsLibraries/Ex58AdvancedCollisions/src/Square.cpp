//
//  Square.cpp
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 7/28/13.
//
//

#include "Square.h"

Square::Square( b2World *world, const Vec2f &position, float angle, float radius ): Particle::Particle( position, angle ) {
    bounds = Rectf( -radius, -radius, radius, radius );
    
    b2BodyDef bd;
    bd.type = b2BodyType::b2_dynamicBody;
    bd.position = Conversions::toPhysics( position );
    bd.angle = toRadians( angle );
    body = world->CreateBody( &bd );
    
    b2FixtureDef fd;
    b2PolygonShape ps;
    float physSize = Conversions::toPhysics( radius );
    ps.SetAsBox( physSize, physSize );
    fd.shape = &ps;
    fd.density = 1.0f;
    fd.friction = 0.04f;
    body->CreateFixture( &fd );
    body->SetAngularVelocity( -10.0f );
    body->SetUserData( new ObjectType( SQUARE_PARTICLE, this ) );
}

void Square::update() {
    Particle::update( body );
}

void Square::draw() const {
    Particle::startDraw();
    gl::drawSolidRect( bounds );
    Particle::endDraw();
}

void Square::killBody( b2World *world ) {
    world->DestroyBody( body );
}

bool Square::isDead() const {
    return Particle::checkIfDead();
}

void Square::onCollisionWith( const int otherObjectKind ) {
    switch ( otherObjectKind ) {
        case TRIANGLE_PARTICLE:
            Particle::setColor( 11.0f / 255, 171.0f / 255, 223.0f / 255 );
            break;
        case CIRCLE_PARTICLE:
            Particle::setColor( 0.0f, 0.0f, 0.0f );
            break;
    }
}