//
//  ParticleSystem.cpp
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "ParticleSystem.h"

void ParticleSystem::update() {
    for(std::vector<Particle>::iterator iter = particles.end() - 1; iter >= particles.begin(); --iter) {
        iter->update();
        if ( iter->isDead() ) {
            particles.erase( iter );
        }
    }
    particles.push_back( Particle( origin, r ) );
}


void ParticleSystem::draw() {
    for( int i = 0; i < particles.size(); i++ ) {
        particles[i].draw();
    }
}