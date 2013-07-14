//
//  Box.h
//  Ex51aBox2DCustom
//
//  Created by Ilya Rostovtsev on 7/9/13.
//
//

#ifndef Ex51aBox2DCustom_Box_h
#define Ex51aBox2DCustom_Box_h

#include "cinder/gl/gl.h"
#include "Box2D/Box2d.h"
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
    Box(b2World* world, float x, float y, float size): bounds( -size/2.0f, -size/2.0f, size/2.0f, size/2.0f ) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set( Conversions::toPhysics(x), Conversions::toPhysics(y) );
        body = world->CreateBody(&bodyDef);
        
        b2PolygonShape dynamicBox;
        float boxSize = Conversions::toPhysics(size/2.0f);
        dynamicBox.SetAsBox(boxSize, boxSize);
        
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
