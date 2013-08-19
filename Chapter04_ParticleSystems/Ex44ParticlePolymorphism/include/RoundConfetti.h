//
//  RoundConfetti.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex44ParticlePolymorphism__RoundConfetti__
#define __Ex44ParticlePolymorphism__RoundConfetti__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"
#include "Circle.h"

using namespace ci;

class RoundConfetti : public Particle {
    
public:
    RoundConfetti( const Vec2f& origin, Rand& random );
    virtual ~RoundConfetti();
    virtual void draw() const;
    // there is no need for an update() implementation - Particle::update() will be called instead
    
private:
    Circle* circle;

};

#endif /* defined(__Ex44ParticlePolymorphism__RoundConfetti__) */
