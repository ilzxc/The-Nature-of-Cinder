//
//  Mover.h
//  Ex23Friction
//
//  Created by Ilya Rostovtsev on 4/12/13.
//
//

#ifndef __Ex23Friction__Mover__
#define __Ex23Friction__Mover__

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

class Mover {
  public:
    Mover();
    void setPosition( ci::Vec2f newPosition );
    void setup( ci::Vec2f gravity, ci::Vec2f wind, float friction );
    void update();
    void draw();
    
    
  private:
    ci::Vec2f position;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
    float fatness; 
    
    ci::Vec2f gravity;
    ci::Vec2f wind;
    ci::Vec2f friction;
    float frictionCoeff;
    
    void applyForces();
    void applyForce( ci::Vec2f force, bool scaleByMass );
    void applyFriction();
    void checkEdges();
};

#endif /* defined(__Ex23Friction__Mover__) */
