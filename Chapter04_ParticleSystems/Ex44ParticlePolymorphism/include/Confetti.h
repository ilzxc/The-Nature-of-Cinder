//
//  Confetti.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__Confetti__
#define __Ex44ParticlePolymorphism__Confetti__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"
#include "Square.h"
#include "Triangle.h"

using namespace ci;

class Confetti : public Particle {
    
public:
    Confetti( const Vec2f& origin, Rand& random, const int type );
    virtual ~Confetti();
    virtual void update();
    virtual void draw() const;
    
private:
    Shape* shape;

};

#endif /* defined(__Ex44ParticlePolymorphism__Confetti__) */
