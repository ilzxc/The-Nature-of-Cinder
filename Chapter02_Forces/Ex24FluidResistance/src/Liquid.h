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
    Liquid( float x, float y, float w, float h, float coeff ): bounds( Rectf(x, y, w, h) ), c( coeff ) { }
    ~Liquid() { }
    
    bool contains( const Mover& m );
    Vec2f drag( const Mover& m );
    void draw();
};

#endif /* defined(__Ex24FluidResistance__Liquid__) */
