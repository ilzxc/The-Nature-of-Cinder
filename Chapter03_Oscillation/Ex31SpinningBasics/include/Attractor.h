//
//  Attractor.h
//  Ex31SpinningBasics
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/17
//

#ifndef __Ex31SpinningBasics__Attractor__
#define __Ex31SpinningBasics__Attractor__

#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;

class Attractor {
public:
    Attractor() { }
    Attractor( const float _x, const float _y );
    
    Vec2f attract( const Mover& m );
    void draw() const;
    void clicked( const Vec2f& mouse );
    void hover( const Vec2f& mouse );
    void stopDragging();
    void drag( const Vec2f& mouse );
    
private:
    float mass;
    float G;
    Vec2f location;
    bool dragging;
    bool rollover;
    Vec2f dragOffset;
};

#endif /* defined(__Ex31SpinningBasics__Attractor__) */
