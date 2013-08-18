//
//  Mover.h
//  Ex21Wind
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
// HWH Maintenance 8/17/13
//

#ifndef __Ex21Wind__Mover__
#define __Ex21Wind__Mover__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Mover {
public:
    Mover();
    void applyForce( const Vec2f& force );
    void update();
    void draw() const;

private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    const float mass;
    const float radius;
    
    void checkEdges();
};

#endif /* defined(__Ex21Wind__Mover__) */
