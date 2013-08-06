//
//  Triugolnik.cpp
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 8/6/13.
//
//

#include "Triugolnik.h"

Triugolnik::Triugolnik( b2World *world, const Vec2f &position, float _angle, float _radius ): Particle::Particle( position, _angle ) {
    points = new Vec2f[3];
    points[0] = Vec2f( 0.0f, -_radius );
    points[1] = Vec2f( _radius, _radius );
    points[2] = Vec2f( -_radius, _radius );
    
    b2BodyDef bd;
    bd.type = b2BodyType::b2_dynamicBody;
    bd.position = Conversions::toPhysics( position );
    bd.angle = toRadians( _angle );
    body = world->CreateBody( &bd );
    
    b2PolygonShape ps;
    b2Vec2 *vertices = new b2Vec2[3];
    for ( int i = 0; i < 3; ++i ) {
        vertices[i] = Conversions::toPhysics( points[i] );
    }
    ps.Set( vertices, 3 );
    delete vertices;

    b2FixtureDef fd;
    fd.shape = &ps;
    fd.density = 1.0f;
    fd.friction = 0.04f;
    body->CreateFixture( &fd );
    body->SetAngularVelocity( 10.0f );
    body->SetUserData( new ObjectType( TRIANGLE_PARTICLE, this ) );
}

void Triugolnik::update() {
    Particle::update( body );
}

void Triugolnik::draw() const {
    Particle::startDraw();
    gl::drawSolidTriangle( points );
    Particle::endDraw();
}

void Triugolnik::killBody( b2World *world ) {
    world->DestroyBody( body );
}

bool Triugolnik::isDead() const {
    return Particle::checkIfDead();
}

void Triugolnik::onCollisionWith( const int otherObjectKind ) {
    switch ( otherObjectKind ) {
        case CIRCLE_PARTICLE:
            Particle::setColor( 11.0f / 255, 223.0f / 255, 118.0f / 255 );
            break;
        case SQUARE_PARTICLE:
            Particle::setColor( 0.0f, 0.0f, 0.0f );
            break;
    }
}