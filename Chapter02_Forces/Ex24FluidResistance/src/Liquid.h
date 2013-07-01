//
//  Liquid.h
//  Ex24FluidResistance
//
//  Created by Ilya Rostovtsev on 5/20/13.
//
//

#ifndef __Ex24FluidResistance__Liquid__
#define __Ex24FluidResistance__Liquid__

#include <iostream>
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

class Liquid {
    
    
public:
    Liquid() { c = 0.8f; }
    Liquid( float const c_ ) : c(c_) { }
    virtual ~Liquid() { }

    bool contains(Mover const& m);
    ci::Vec2f drag(Mover const& m);
    void draw();
    void setBounds();
    
private:
    ci::Rectf dimensions;
    float c; // coefficient of drag

};

#endif /* defined(__Ex24FluidResistance__Liquid__) */
