//
//  Attractor.h
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 5/24/13.
//
//

#ifndef __Ex25GravitationalAttractors__Attractor__
#define __Ex25GravitationalAttractors__Attractor__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

class Attractor {
    
public:
    Attractor()
    :   mass(20.0f),
        G(1),
        dragOffset(0.0f, 0.0f)
    { }
    
    void setLocation( ci::Vec2f const& newLoc );
    ci::Vec2f attract( Mover const& m );
    void draw();
    void clicked( ci::Vec2f const& mouse );
    void hover( ci::Vec2f const& mouse );
    void stopDragging();
    void drag( ci::Vec2f const& mouse );
    
private:
    const float mass;
    const float G;
    ci::Vec2f location;
    bool dragging = false;
    bool rollover = false;
    ci::Vec2f dragOffset;
};

#endif /* defined(__Ex25GravitationalAttractors__Attractor__) */
