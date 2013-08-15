//
//  ArmComponent.cpp
//  Ex59AdvancedJoints
//
//  Created by Ilya Rostovtsev on 8/14/13.
//
//

#include "ArmComponent.h"

ArmComponent::ArmComponent( b2World *world, const float x, const float y, const float width, const float height, const bool dynamic ) {
    position = Vec2f( x + (width / 2), y + (height / 2) );
    armRect = Rectf( -width / 2.0f, -height / 2.0f, width / 2.0f, height / 2.0f );
    
    b2BodyDef bd;
    bd.position = Conversions::toPhysics( position );
    bd.type = ( dynamic ) ? b2BodyType::b2_dynamicBody : b2BodyType::b2_staticBody;
    body = world->CreateBody( &bd );

    b2FixtureDef fd;
    b2PolygonShape ps;
    ps.SetAsBox( Conversions::toPhysics( width / 2.0f ), Conversions::toPhysics( height / 2.0f ) );
    fd.shape = &ps;
    fd.density = 3.0f;
    fd.restitution = 0.3f;
    fd.friction = 5.7f;
    body->CreateFixture( &fd );
}

b2Body* ArmComponent::getBody() {
    return body;
}

void ArmComponent::update() {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
}

void ArmComponent::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( 0.444f, 0.444f, 0.444f );
    gl::drawStrokedRect( armRect );
    gl::popMatrices();
}