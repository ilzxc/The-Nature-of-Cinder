//
//  Arm.cpp
//  Ex59AdvancedJoints
//
//  Created by Ilya Rostovtsev on 8/14/13.
//
//

#include "Arm.h"

Arm::Arm( b2World *world ) {
    // fixed object:
    FullArm.push_back( std::unique_ptr< ArmComponent > ( new ArmComponent( world, 100, 100, 50, 50, false ) ) );
    FullArm.push_back( std::unique_ptr< ArmComponent > ( new ArmComponent( world, 112.5, 112.5, 200, 25, true ) ) );
    FullArm.push_back( std::unique_ptr< ArmComponent > ( new ArmComponent( world, 300 - 12.5, 112.5, 25, 150, true ) ) );
    FullArm.push_back( std::unique_ptr< ArmComponent > ( new ArmComponent( world, 300 - 12.5, 262.5, 25, 25, true ) ) );
    
    b2RevoluteJointDef rjd;
    rjd.Initialize( FullArm[0]->getBody(), FullArm[1]->getBody(), Conversions::toPhysics( Vec2f( 125, 125 ) ) );
    world->CreateJoint( &rjd );

    rjd.Initialize( FullArm[1]->getBody(), FullArm[2]->getBody(), Conversions::toPhysics( Vec2f( 300, 125 ) ) );
    world->CreateJoint( &rjd );
    
    rjd.Initialize( FullArm[2]->getBody(), FullArm[3]->getBody(), Conversions::toPhysics( Vec2f( 300, 275 ) ) );
    world->CreateJoint( &rjd );
}

Arm::~Arm() {
    FullArm.clear();
}

void Arm::update( const Vec2f &mouse ) {
    for ( auto& component : FullArm ) {
        component->update();
    }
    
    if ( mouse.x != 0 && mouse.y != 0 ) {
        // FullArm[3]->getBody()->SetTransform( Conversions::toPhysics( mouse ), 0.0f );
        Vec2f diff = mouse - Conversions::toScreen( FullArm[3]->getBody()->GetPosition() );
        diff.normalize();
        diff *= 20000.0f;
        FullArm[3]->getBody()->ApplyForce( Conversions::toPhysics( diff ), FullArm[3]->getBody()->GetPosition() );
    }
}

void Arm::draw() const {
    for ( auto& component : FullArm ) {
        component->draw();
    }
}