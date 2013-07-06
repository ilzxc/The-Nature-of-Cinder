//
//  ParticleSystem.h
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#ifndef __Ex43ParticleSystems__ParticleSystem__
#define __Ex43ParticleSystems__ParticleSystem__

#include "cinder/Rand.h"
#include "Particle.h"
#include <vector>

using namespace ci;

class ParticleSystem {
    
private:
    std::vector<Particle> particles;
    Vec2f origin;
    Rand r;
    
public:
    ParticleSystem( Vec2f o, float seed ): origin(o) {
        r.seed( seed );
        particles.push_back( Particle( origin, r ) );
    }
    ~ParticleSystem() { }
    void update();
    void draw();
};

#endif /* defined(__Ex43ParticleSystems__ParticleSystem__) */
