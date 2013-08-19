//
//  Particle.h
//  Ex41SingleParticle
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex41SingleParticle__Particle__
#define __Ex41SingleParticle__Particle__

#include "cinder/gl/gl.h"
#include "Cinder/Rand.h"

using namespace ci;

class Particle {
    
public:
    Particle( const Vec2f& location_, const Vec2f& acceleration_ );
    
    void update();
    void draw() const;
    bool isDead() const;
    
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;

};

#endif /* defined(__Ex41SingleParticle__Particle__) */
