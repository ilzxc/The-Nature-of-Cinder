//
//  Attractor.h
//  Ex31SpinningBasics
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex31SpinningBasics__Attractor__
#define __Ex31SpinningBasics__Attractor__

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
    Attractor( float x, float y ): mass(30.0f), G(1.5f), location( Vec2f(x, y) ), dragging(false), rollover(false), dragOffset( Vec2f::zero() ) { }
    ~Attractor() { }
    
    Vec2f attract( const Mover& m );
    void draw();
    void clicked( const Vec2f& mouse );
    void hover( const Vec2f& mouse );
    void stopDragging();
    void drag( const Vec2f& mouse );
};

#endif /* defined(__Ex31SpinningBasics__Attractor__) */
