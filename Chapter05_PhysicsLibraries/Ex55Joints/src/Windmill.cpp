//
//  Windmill.cpp
//  Ex55Joints
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#include "Windmill.h"

Windmill::Windmill( b2World *world, const Vec2f &_position ): position( _position ) {
    // Screen:
    float baseWidth = 10.0f;
    float baseHeight = 30.0f;
    Vec2f basePosition = Vec2f( _position.x - (baseWidth / 2.0f), _position.y - (baseHeight / 2.0f) );
    float bladeWidth = 100.0f;
    float bladeHeight = 5.0f;
    Vec2f bladeLocation = Vec2f( basePosition.x, basePosition.y + bladeHeight );
    
    baseBox = Rectf( -baseWidth / 2.0f, -baseHeight / 2.0f, baseWidth / 2.0f, baseWidth / 2.0f );
    bladesBox = Rectf( -bladeWidth / 2.0f, -bladeHeight / 2.0f, bladeWidth / 2.0f, bladeHeight / 2.0f );
    bladesPosition = Vec2f(0.0f, -baseHeight / 2.0f + bladeHeight );
    
    // Base:
    b2BodyDef bdBody;
    bdBody.position.Set( Conversions::toPhysics( basePosition.x ), Conversions::toPhysics( basePosition.y ) );
    bdBody.type = b2BodyType::b2_staticBody;
    base = world->CreateBody( &bdBody );
    
    b2PolygonShape psBody;
    psBody.SetAsBox( Conversions::toPhysics( baseWidth / 2.0f ), Conversions::toPhysics( baseHeight / 2.0f ) );
    b2FixtureDef fdBody;
    fdBody.shape = &psBody;
    base->CreateFixture( &fdBody );
    
    // Blades:
    b2BodyDef bdBlade;
    bdBlade.position.Set( Conversions::toPhysics( bladeLocation.x ), Conversions::toPhysics( bladeLocation.y ) );
    bdBlade.type = b2BodyType::b2_dynamicBody;
    blades = world->CreateBody( &bdBlade );
    
    b2PolygonShape psBlade;
    psBlade.SetAsBox( Conversions::toPhysics( bladeWidth / 2.0f ), Conversions::toPhysics( bladeHeight / 2.0f ) );
    b2FixtureDef fdBlade;
    fdBlade.shape = &psBlade;
    fdBlade.density = 2.0f;
    fdBlade.friction = 0.3f;
    fdBlade.restitution = 0.9f;
    blades->CreateFixture( &fdBlade );
    
    b2RevoluteJointDef rjd;
    rjd.Initialize( base, blades, Conversions::toPhysics( bladeLocation ) );
    rjd.motorSpeed = 5.0f * M_PI;
    rjd.maxMotorTorque = 1000.0f;
    rjd.enableMotor = true;
    
    joint = (b2RevoluteJoint*)world->CreateJoint( &rjd );
}

void Windmill::update() {
    bladesAngle = toDegrees( blades->GetAngle() );
}

void Windmill::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::drawSolidRect( baseBox );
    gl::translate( bladesPosition );
    gl::rotate( bladesAngle );
    gl::drawSolidRect( bladesBox );
    gl::popMatrices();
}

void Windmill::toggleMotor() {
    joint->EnableMotor( !( joint->IsMotorEnabled() ) );
}

void Windmill::killBody( b2World *world ) {
    world->DestroyJoint( joint );
    world->DestroyBody( blades );
    world->DestroyBody( base );
}