//
//  Confetti.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Confetti__
#define __Ex44ParticlePolymorphism__Confetti__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"
#include "Square.h"
#include "Triangle.h"

using namespace ci;

class Confetti: public Particle {
private:
    Shape *shape;

public:
    Confetti( const Vec2f origin, Rand& r, int type )
    : Particle::Particle(origin, r) {
        if( type == 0 ) {
            shape = new Square( Particle::getRadius(), r.nextFloat(0, 360), r.nextFloat(-7.5f, 7.5f) );
        } else {
            shape = new Triangle( Particle::getRadius(), r.nextFloat(0, 360), r.nextFloat(-7.5f, 7.5f) );
        }
    }
    ~Confetti() { delete shape; }
    void update();
    void draw();
};

#endif /* defined(__Ex44ParticlePolymorphism__Confetti__) */
