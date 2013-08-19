//
//  Particle.h
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex43ParticleSystems__Particle__
#define __Ex43ParticleSystems__Particle__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
    
public:
    Particle( const Vec2f& origin_, Rand& random_ );
    void update();
    void draw() const;
    bool isDead() const;
    
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    float aging;
    float sizeRadius;

};

#endif /* defined(__Ex43ParticleSystems__Particle__) */
