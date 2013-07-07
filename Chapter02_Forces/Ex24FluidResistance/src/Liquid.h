//
//  Liquid.h
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 7/6/13.
//
//

#ifndef __Ex24FluidResistance__Liquid__
#define __Ex24FluidResistance__Liquid__

#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;

class Liquid {
private:
    Rectf bounds;
    float c;

public:
    Liquid() { }
    Liquid( float x1, float y1, float x2, float y2, float coeff ): bounds( x1, y1, x2, y2 ), c( coeff ) { }
    ~Liquid() { }
    
    bool contains( const Mover& m );
    Vec2f drag( const Mover& m );
    void draw();
};

#endif /* defined(__Ex24FluidResistance__Liquid__) */
