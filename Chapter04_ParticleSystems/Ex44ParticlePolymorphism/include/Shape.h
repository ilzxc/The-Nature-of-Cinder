//
//  Shape.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__Shape__
#define __Ex44ParticlePolymorphism__Shape__

using namespace ci;

class Shape {
    
public:
    Shape( const float r, const float g, const float b ): color( r, g, b ) { }
    virtual ~Shape() { }
    virtual void update() = 0;
    virtual void draw() const = 0;
    
    const Vec3f color;

};

#endif /* defined(__Ex44ParticlePolymorphism__Shape__) */
