//
//  ParticleSystem.cpp
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/19/13
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem( const Vec2f& origin_, const float seed_ ): origin( origin_ ) {
    random.seed( seed_ );
    particles.push_back( Particle( origin, random ) );
}

void ParticleSystem::update()
{
    for( std::vector< Particle >::iterator iter = particles.begin(); iter != particles.end(); ) {
        iter->update();
        if ( iter->isDead() ) {
            iter = particles.erase( iter );
        } else {
            ++iter;
        }
    }
    particles.push_back( Particle( origin, random ) );
}


void ParticleSystem::draw() const
{
    for( auto& particle : particles ) {
        particle.draw();
    }
}