//
//  Circle.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__Circle__
#define __Ex44ParticlePolymorphism__Circle__

#include "cinder/gl/gl.h"
#include "Shape.h"

using namespace ci;

class Circle : public Shape {
    
public:    
    Circle( const float radius_ );
    virtual void update();
    virtual void draw() const;
    
private:
    const float radius;

};

#endif /* defined(__Ex44ParticlePolymorphism__Circle__) */
