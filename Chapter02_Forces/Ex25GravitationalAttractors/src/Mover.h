//
//  Mover.h
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 5/24/13.
//
//

#ifndef __Ex25GravitationalAttractors__Mover__
#define __Ex25GravitationalAttractors__Mover__

#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

class Mover {
public:
    Mover()
    :   mass(1.0f),
        location(400.0f, 50.0f),
        velocity(1.0f, 0.0f),
        acceleration(0.0f, 0.0f)
    { }
    
    Mover( float fat )
    :   mass(fat),
        location(0.0f, 0.0f),
        velocity(0.0f, 0.0f),
        acceleration(0.0f, 0.0f)
    { }
    
    void applyForce( ci::Vec2f const& force );
    void update();
    void draw();
    void checkEdges();
    
    ci::Vec2f location;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
    float const mass;
};

#endif /* defined(__Ex25GravitationalAttractors__Mover__) */
