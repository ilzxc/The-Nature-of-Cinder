//
//  Boundary.h
//  Ex55Joints (via Ex52FixedObjects)
//
//  Created by Ilya Rostovtsev on 7/12/13.
//
//

#ifndef Ex52FixedObjects_Boundary_h
#define Ex52FixedObjects_Boundary_h

#include "cinder/gl/gl.h"
#include "Box2D/Box2D.h"
#include "Conversions.h"

using namespace ci;

class Boundary {
private:
    Rectf   bounds;
    b2Body* body;
    Vec2f   position;
    
public:
    Boundary(){}
    Boundary(b2World* world, float x, float y, float w, float h): bounds( -w/2.0, -h/2.0, w/2.0, h/2.0 ), position(x + w/2.0, y + h/2.0) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_staticBody;
        bodyDef.position.Set( Conversions::toPhysics(x + w/2), Conversions::toPhysics(y + h/2) );
        body = world->CreateBody(&bodyDef);
        
        b2PolygonShape staticBox;
        staticBox.SetAsBox(Conversions::toPhysics(w/2), Conversions::toPhysics(h/2));
        
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &staticBox;
        
        body->CreateFixture(&fixtureDef);
        
        // position = Conversions::toScreen( body->GetPosition() );
    }
    
    void draw() const;
};

#endif
