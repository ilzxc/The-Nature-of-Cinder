//
//  Particle.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/19/13
//

/*****
 *
 *  Particle.h is an abstract base class, which handles the behaviors
    defined in previous examples - it updates position and lifespan of
    particles, and provides a pure virtual function for draw().
 
    This abstract base class is extended by Confetti and RoundConfetti
    classes.                                                            *
                                                                        *
                                                                    *****/

#ifndef __Ex44ParticlePolymorphism__Particle__
#define __Ex44ParticlePolymorphism__Particle__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Square.h"

using namespace ci;

class Particle {
    
public:
    Particle( const Vec2f& origin, Rand& r );
    virtual ~Particle() {}
    
    virtual void update();
    virtual void draw() const = 0;
    void draw( const Shape& shape ) const;
    bool isDead() const;
    float getRadius() const;
    float getLifespan() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    const float aging;
    const float sizeRadius;

};

#endif /* defined(__Ex44ParticlePolymorphism__Particle__) */
