//
//  Microphone.cpp
//  Ex54ComplexForms
//
//  Created by Ilya Rostovtsev on 7/17/13.
//
//

#include "Microphone.h"

Microphone::Microphone( b2World *world, const Vec2f &_position ) {
    Rand::randomize();
    // Pixels:
    Vec2f dimensions = Vec2f( Rand::randFloat( 8, 16 ), Rand::randFloat( 24, 48 ) );
    box = Rectf( -dimensions.x / 2, -dimensions.y / 2, dimensions.x / 2, dimensions.y / 2 );
    radius = Rand::randFloat( 8, 16 );
    
    // Box2D:    
    b2BodyDef bodyDefinition;
    bodyDefinition.type = b2BodyType::b2_dynamicBody;
    bodyDefinition.position = Conversions::toPhysics( _position );
    body = world->CreateBody( &bodyDefinition );
    
    b2CircleShape circle;
    circle.m_radius = Conversions::toPhysics( radius );
    b2Vec2 offset = Conversions::toPhysics( Vec2f( 0.0f, -dimensions.y / 2.0f ) );
    circle.m_p.Set( offset.x, offset.y );
    
    b2PolygonShape square;
    b2Vec2 squareDimensions = Conversions::toPhysics( dimensions / 2.0f );
    square.SetAsBox(squareDimensions.x, squareDimensions.y);
        
    body->CreateFixture( &square, 1.0 );
    body->CreateFixture( &circle, 1.0 );
    
    body->SetLinearVelocity( b2Vec2( Rand::randFloat(-1.0f, 1.0f), Rand::randFloat(-5.0, -2.0f) ) );
    body->SetAngularVelocity( Rand::randFloat( -5.0f, 5.0f ) );
}

void Microphone::update() {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
}

void Microphone::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::color( 186.0f/255, 194.0f/255, 195.0f/255 );
    gl::drawSolidRect( box );
    gl::drawSolidCircle( Vec2f( 0.0, box.getY1() ), radius );
    gl::popMatrices();    
}

bool Microphone::isDead() const {
    if ( position.y > app::getWindowHeight() + 100.0f ) {
        return true;
    }
    return false;    
}

void Microphone::killBody( b2World *world ) {
    world->DestroyBody( body );
    body = NULL;
}

