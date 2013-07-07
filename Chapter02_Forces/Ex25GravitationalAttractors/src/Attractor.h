//
//  Attractor.h
//  Ex25GravitationalAttractors
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#ifndef __Ex25GravitationalAttractors__Attractor__
#define __Ex25GravitationalAttractors__Attractor__

#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;

class Attractor {
private:
    float mass;
    float G;
    Vec2f location;
    bool dragging;
    bool rollover;
    Vec2f dragOffset;
    
public:
    Attractor() { }
    Attractor( float x, float y ): mass(20.0f), G(1.0f), location( Vec2f(x, y) ), dragging(false), rollover(false), dragOffset( Vec2f::zero() ) { }
    ~Attractor() { }
    
    Vec2f attract( Mover& m );
    void draw();
    void clicked( int mx, int my );
    void hover( int mx, int my );
    void stopDragging();
    void drag();
};

#endif /* defined(__Ex25GravitationalAttractors__Attractor__) */
