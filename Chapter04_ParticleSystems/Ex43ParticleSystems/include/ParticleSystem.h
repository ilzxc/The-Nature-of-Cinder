//
//  ParticleSystem.h
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex43ParticleSystems__ParticleSystem__
#define __Ex43ParticleSystems__ParticleSystem__

#include "cinder/Rand.h"
#include "Particle.h"
#include <vector>

using namespace ci;

class ParticleSystem {
    
public:
    ParticleSystem( const Vec2f& origin_, const float seed_ );
    void update();
    void draw() const;
    
private:
    std::vector< Particle > particles;
    Vec2f origin;
    Rand random;
    
};

#endif /* defined(__Ex43ParticleSystems__ParticleSystem__) */
