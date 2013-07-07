//
//  Particle.h
//  Ex41SingleParticle
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#ifndef __Ex41SingleParticle__Particle__
#define __Ex41SingleParticle__Particle__

#include "cinder/gl/gl.h"
#include "Cinder/Rand.h"

using namespace ci;

class Particle {
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    
public:
    Particle(Vec2f l, Vec2f a) :
        location( l ),
        velocity( 0.0f, 0.05f ),
        acceleration( a ),
        lifespan( 1.0f ) { }
    ~Particle() { }
    
    void update();
    void display();
    bool isDead();
};

#endif /* defined(__Ex41SingleParticle__Particle__) */
