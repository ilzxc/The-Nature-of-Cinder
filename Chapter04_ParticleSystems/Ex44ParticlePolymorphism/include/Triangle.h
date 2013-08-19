//
//  Triangle.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__Triangle__
#define __Ex44ParticlePolymorphism__Triangle__

#include "cinder/gl/gl.h"
#include "Shape.h"
#include "Rotational.h"

using namespace ci;

class Triangle: public Shape, public Rotational {
    
public:
    Triangle( const float radius, const float initialAngle, const float rotationSpeed );
    virtual void update();
    virtual void draw() const;
    
private:
    Vec2f p1, p2, p3;

};

#endif /* defined(__Ex44ParticlePolymorphism__Triangle__) */
