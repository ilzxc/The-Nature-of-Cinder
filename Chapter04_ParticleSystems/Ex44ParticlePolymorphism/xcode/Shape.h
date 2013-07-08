//
//  Shape.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Shape__
#define __Ex44ParticlePolymorphism__Shape__

using namespace ci;

class Shape {
public:
    const Vec3f color;
    virtual void update() = 0;
    virtual void draw() const = 0;
    Shape( float r, float g, float b ): color(r, g, b){ }
    virtual ~Shape() { } 
};

#endif /* defined(__Ex44ParticlePolymorphism__Shape__) */
