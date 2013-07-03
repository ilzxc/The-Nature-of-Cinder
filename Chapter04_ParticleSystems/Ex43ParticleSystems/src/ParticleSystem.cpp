//
//  ParticleSystem.cpp
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "ParticleSystem.h"

void ParticleSystem::update() {
    for(std::vector<Particle>::reverse_iterator iter = particles.rbegin(); iter != particles.rend(); ++iter) {
        iter->update();
        if ( iter->isDead() ) {
            particles.erase( --iter.base() );
        }
    }
    particles.push_back( Particle( origin, r ) );
}


void ParticleSystem::draw() {
    for( int i = 0; i < particles.size(); i++ ) {
        particles[i].draw();
    }
}