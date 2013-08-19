//
//  CustomShape.cpp
//  Ex54ComplexForms
//
//  Created by Ilya Rostovtsev on 7/16/13.
//
//

#include "CustomShape.h"

CustomShape::CustomShape( b2World *world, const Vec2f& where ) {
    Rand::randomize();
    
    // Screen Units:
    float angle = 0.0f;
    const int numPoints = Rand::randInt(4, 9);
    const float step = 2.0f * M_PI / numPoints;
    const float minAngle = step / 4.0f;
    float radius = Rand::randFloat( 12.5f, 25.0f );
    float leftover = 0.0f;
    
    for (int i = 0; i < numPoints; ++i) {
        float maxAngle = step + leftover;
        angle += Rand::randFloat(minAngle, maxAngle);
        leftover = (i * step) - angle;
        polygon.push_back( Vec2f( radius * cos( angle ), radius * sin( angle ) ) );
    }
    
    startPoint = (polygon[0] + polygon[polygon.size() - 1]) / 2.0f;
    
    // Box2D Units:
    b2Vec2 b2dPosition = Conversions::toPhysics( where );
    b2Vec2 *b2Polygon = new b2Vec2[numPoints];
    int i = 0;
    for ( auto& vecs : polygon ) {
        b2Polygon[i] = Conversions::toPhysics( vecs );
        ++i;
    }
    
    b2PolygonShape ps;
    ps.Set( b2Polygon, numPoints );
    
    b2BodyDef bd;
    bd.type = b2BodyType::b2_dynamicBody;
    bd.position = b2dPosition;
    body = world->CreateBody( &bd );
    
    b2FixtureDef fd;
    fd.shape = ( &ps );
    fd.density = 1.0f;
    fd.friction = 0.3f;
    body->CreateFixture( &fd );
    
    body->SetLinearVelocity( b2Vec2( Rand::randFloat(-1.0f, 1.0f), Rand::randFloat(-5.0f, -2.0f) ) );
    body->SetAngularVelocity( Rand::randFloat(-5.0f, 5.0f) );
    
    delete b2Polygon;
}

void CustomShape::update( b2World *world ) {
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
}

void CustomShape::draw() const {
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );

    gl::color( 186.0f/255, 194.0f/255, 195.0f/255 );
    gl::begin( GL_TRIANGLE_FAN );
    gl::vertex( startPoint );
    for( auto& vecs : polygon ) {
        gl::vertex( vecs );
    }
    gl::end();
    gl::popMatrices();
}

bool CustomShape::isDead() const {
    if (position.y > app::getWindowHeight() + 100.0f) {
        return true;
    }
    return false;
}

void CustomShape::killBody( b2World *world ) {
    world->DestroyBody( body );
    body = NULL;
}