//
//  Rotational.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Rotational__
#define __Ex44ParticlePolymorphism__Rotational__

#include "cinder/gl/gl.h"

using namespace ci;

class Rotational {
private:
    float rotation;
    float rotationSpeed;
    
public:
    Rotational() { }
    Rotational( float r, float rS ): rotation( r ), rotationSpeed( rS ) { }
    void update();
    void draw() const;
};

#endif /* defined(__Ex44ParticlePolymorphism__Rotational__) */
