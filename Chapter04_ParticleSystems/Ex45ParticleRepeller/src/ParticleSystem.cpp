//
//  ParticleSystem.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem( const Vec2f& origin_ )
: origin( origin_ )
{ }

ParticleSystem::~ParticleSystem()
{
    particles.clear();
}

void ParticleSystem::update( const Vec2f& gravity, Repeller& repeller, Rand& random )
{
    {
        const int numParticlesToAdd = 2; // change to increase or decrease # of particles added each frame
        
        for ( int i = 0; i < numParticlesToAdd; ++i ) {
            addParticle( random );
        }
    }

    for ( auto& p : particles ) {
        p->applyForce( gravity );                               // apply gravity
        p->applyForce( repeller.repel( p->getPosition() ) );    // apply repeller
        p->update();                                            
    }
    particles.erase( std::remove_if( particles.begin(), particles.end(), std::mem_fn( &Particle::isDead ) ), particles.end() );
}

void ParticleSystem::draw() const
{
    for( auto& p : particles ) {
        p->draw();
    }
}

void ParticleSystem::addParticle( Rand& random )
{
    particles.push_back( std::unique_ptr< Particle > ( new Particle( origin, random ) ) );
}