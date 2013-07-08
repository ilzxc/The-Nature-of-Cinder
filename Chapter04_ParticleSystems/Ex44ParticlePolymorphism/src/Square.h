//
//  Square.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Square__
#define __Ex44ParticlePolymorphism__Square__

#include "cinder/gl/gl.h"

using namespace ci;

class Square {
private:
    Rectf bounds;
    
public:
    Square(): bounds() { }
    Square( float side ): bounds( -side, -side, side, side ) { }
    void draw() const;
};

#endif /* defined(__Ex44ParticlePolymorphism__Square__) */
