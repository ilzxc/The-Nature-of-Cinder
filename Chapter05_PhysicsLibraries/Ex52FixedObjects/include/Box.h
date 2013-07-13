//
//  Box.h
//  Ex52FixedObjects
//
//  Created by Ilya Rostovtsev on 7/12/13.
//
//

#ifndef Ex52FixedObjects_Box_h
#define Ex52FixedObjects_Box_h

#include "cinder/gl/gl.h"
#include "Box2D/Box2D.h"
#include "Conversions.h"

using namespace ci;

class Box {
private:
    Rectf   bounds;
    b2Body* body;
    Vec2f   position;
    float   angle;
    
public:
    Box(){}
    Box(b2World* world, float x, float y, float sizeX, float sizeY): bounds( -(sizeX + 7)/2.0f, -(sizeY + 7)/2.0f, (sizeX + 7)/2.0f, (sizeY + 7)/2.0f ) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set( Conversions::toPhysics(x), Conversions::toPhysics(y) );
        body = world->CreateBody(&bodyDef);
        
        b2PolygonShape dynamicBox;
        b2Vec2 boxSize = Conversions::toPhysics( Vec2f(sizeX, sizeY) );
        dynamicBox.SetAsBox(boxSize.x, boxSize.y);
        
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        
        body->CreateFixture(&fixtureDef);
    }
    void update(b2World * world);
    void draw() const;
    bool isDead();
    b2Body* getBody();
};

#endif
