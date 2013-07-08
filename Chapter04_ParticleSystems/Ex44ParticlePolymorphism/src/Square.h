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
#include "Shape.h"
#include "Rotational.h"

using namespace ci;

class Square: public Shape, public Rotational {
private:
    Rectf bounds;
    
    
public: 
    Square(): Square::Square(5.0f, 0.0f, 0.0f) { }
    Square( float side, float initialAngle, float rotationSpeed )
    : Rotational( initialAngle, rotationSpeed ),
      bounds( -side, -side, side, side ),
      Shape::Shape(54.0f/255, 33.0f/255, 68.0f/255) { }
    void update();
    void draw() const;
};

#endif /* defined(__Ex44ParticlePolymorphism__Square__) */
