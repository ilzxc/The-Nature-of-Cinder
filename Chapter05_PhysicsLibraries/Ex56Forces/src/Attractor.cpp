//
//  Attractor.cpp
//  Ex56Forces
//
//  Created by Ilya Rostovtsev on 7/23/13.
//
//

#include "Attractor.h"

Attractor::Attractor( b2World *world, float x, float y )
  : mass(30.0f),
    G(9.8f),
    location( x, y ),
    dragging(false),
    rollover(false),
    dragOffset( Vec2f::zero() ) {
        b2BodyDef bd;
        bd.position = Conversions::toPhysics( location );
        bd.type = b2BodyType::b2_staticBody;
        body = world->CreateBody( &bd );
        
        b2CircleShape cs;
        cs.m_radius = Conversions::toPhysics( mass );
        b2FixtureDef fd;
        fd.shape = &cs;
        fd.density = 3.0f;
        fd.friction = 0.08f;
        fd.restitution = 0.3f;
        
        body->CreateFixture( &fd );
}

b2Vec2 Attractor::attract( const Particle& p ) const {
    b2Vec2 force = body->GetPosition() - p.getBody()->GetPosition();
    float d = force.Length();
    d = (d < 5.0) ? 5.0 : ( (d > 25.0) ? 25.0 : d);
    force.Normalize();
    float strength = (G * mass * p.getBody()->GetMass() ) / (d * d);
    force *= strength;
    return force;
}


void Attractor::draw() const {
    if (rollover) {
        gl::color( 0.9f, 0.9f, 0.9f );
    } else {
        gl::color( 0.66f, 0.66f, 0.66f );
    }
    gl::drawSolidCircle( location, mass );
    
}

void Attractor::clicked( const Vec2f& mouse ) {
    float d = mouse.distance( location );
    if (d < mass) {
        dragging = true;
        dragOffset = location - mouse;
    }
}

void Attractor::hover( const Vec2f& mouse ) {
    float d = mouse.distance( location );
    if (d < mass) {
        rollover = true;
    } else {
        rollover = false;
    }
}

void Attractor::stopDragging() {
    dragging = false;
}

void Attractor::drag( const Vec2f& mouse ) {
    if (dragging) {
        location = (mouse + dragOffset);
    }
    body->SetTransform( Conversions::toPhysics( location ), 0.0f ); // no rotation required
}

void Attractor::destroyBody( b2World *world ) {
    world->DestroyBody( body );
}