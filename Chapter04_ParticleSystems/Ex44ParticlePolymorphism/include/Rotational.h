//
//  Rotational.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__Rotational__
#define __Ex44ParticlePolymorphism__Rotational__

#include "cinder/gl/gl.h"

using namespace ci;

class Rotational {
    
public:
    Rotational( const float rotation_, const float rotationSpeed_ );
    void update();
    void draw() const;
    
private:
    float rotation;
    float rotationSpeed;

};

#endif /* defined(__Ex44ParticlePolymorphism__Rotational__) */
