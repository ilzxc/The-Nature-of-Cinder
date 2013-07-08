//
//  RoundConfetti.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#ifndef __Ex44ParticlePolymorphism__RoundConfetti__
#define __Ex44ParticlePolymorphism__RoundConfetti__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"
#include "Circle.h"

using namespace ci;

class RoundConfetti: public Particle {
private:
    Circle circle;
    
public:
    RoundConfetti( const Vec2f origin, Rand& r )
    : Particle(origin, r), circle( Particle::getRadius() ) { }
    void draw();
};

#endif /* defined(__Ex44ParticlePolymorphism__RoundConfetti__) */
