//
//  Triangle.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Triangle__
#define __Ex44ParticlePolymorphism__Triangle__

#include "cinder/gl/gl.h"
#include "Shape.h"
#include "Rotational.h"

using namespace ci;

class Triangle: public Shape, public Rotational {
private:
    Vec2f p1, p2, p3;
    
public:
    Triangle(): Triangle::Triangle(5.0f, 0.0f, 0.0f) { }
    Triangle( float radius, float initialAngle, float rotationSpeed )
    : Rotational( initialAngle, rotationSpeed ),
    p1( 0.0f, -radius ), p2( radius, radius ), p3( -radius, radius ),
    Shape::Shape(218.0f/255, 52.0f/255, 48.0f/255) { }
    void update();
    void draw() const;
};

#endif /* defined(__Ex44ParticlePolymorphism__Triangle__) */
