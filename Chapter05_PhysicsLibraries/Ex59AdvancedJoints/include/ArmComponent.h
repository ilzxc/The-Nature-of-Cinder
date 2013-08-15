//
//  ArmComponent.h
//  Ex59AdvancedJoints
//
//  Created by Ilya Rostovtsev on 8/14/13.
//
//

#ifndef Ex59AdvancedJoints_ArmComponent_h
#define Ex59AdvancedJoints_ArmComponent_h

#include "Box2D/Box2D.h"
#include "cinder/gl/gl.h"
#include "Conversions.h"

using namespace ci;

class ArmComponent {
public:
    ArmComponent() { }
    ArmComponent( b2World *world, const float x, const float y, const float width, const float height, const bool dynamic );
    b2Body* getBody();
    void update();
    void draw() const;
    
private:
    Rectf armRect;
    b2Body *body;
    Vec2f position;
    float angle;
};

#endif
