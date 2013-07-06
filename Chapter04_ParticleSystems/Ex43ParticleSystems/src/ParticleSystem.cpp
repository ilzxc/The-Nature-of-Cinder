//
//  ParticleSystem.cpp
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "ParticleSystem.h"

void ParticleSystem::update() {
    for(std::vector<Particle>::iterator iter = particles.begin(); iter != particles.end();) {
        iter->update();
        if ( iter->isDead() ) {
            iter = particles.erase(iter);
        } else {
            ++iter;
        }
    }
    particles.push_back( Particle( origin, r ) );
}


void ParticleSystem::draw() {
    for( auto& particle : particles ) {
        particle.draw();
    }
}