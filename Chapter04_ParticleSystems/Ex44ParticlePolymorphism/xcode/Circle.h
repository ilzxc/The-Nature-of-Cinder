//
//  Circle.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Circle__
#define __Ex44ParticlePolymorphism__Circle__

#include "cinder/gl/gl.h"
#include "Shape.h"


using namespace ci;

class Circle: public Shape {
private:
    float radius;
    
public:    
    Circle(): Circle::Circle(5.0f) { }
    Circle( float r ): radius(r), Shape::Shape(154.0f/255, 40.0f/255, 47.0f/255) { }
    void update();
    void draw() const;
};

#endif /* defined(__Ex44ParticlePolymorphism__Circle__) */
