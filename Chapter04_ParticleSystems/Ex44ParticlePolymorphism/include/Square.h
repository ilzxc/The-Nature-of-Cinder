//
//  Square.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__Square__
#define __Ex44ParticlePolymorphism__Square__

#include "cinder/gl/gl.h"
#include "Shape.h"
#include "Rotational.h"

using namespace ci;

class Square : public Shape, public Rotational {
    
public:
    Square( const float side, const float initialAngle, const float rotationSpeed );
    virtual void update();
    virtual void draw() const;
    
private:
    Rectf bounds;

};

#endif /* defined(__Ex44ParticlePolymorphism__Square__) */
