//
//  ParticleSystem.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "ParticleSystem.h"

ParticleSystem::~ParticleSystem() {
    for (int i = 0; i < particles.size(); i++) {
        delete particles[i];
    }
}

void ParticleSystem::update( const Vec2f& force, Repeller& repeller, Rand& random ) {
    applyForce( force );
    applyRepeller( repeller );
    for(std::vector<Particle*>::reverse_iterator iter = particles.rbegin(); iter != particles.rend(); ++iter) {
        (*iter)->update();
        if ( (*iter)->isDead() ) {
            particles.erase( --iter.base() );
        }
    }
    addParticle( random );
    addParticle( random );
    
    // std::cout << "total number of particles present is " << particles.size() << std::endl;
}

void ParticleSystem::draw() {
    for( int i = 0; i < particles.size(); i++ ) {
        particles[i]->draw();
    }
}

void ParticleSystem::addParticle( Rand& r ) {
    particles.push_back( new Particle( origin, r ) );
}

void ParticleSystem::applyForce( const Vec2f& f ) {
    for (int i = 0; i < particles.size(); i++ ) {
        particles[i]->applyForce(f);
    }
}

void ParticleSystem::applyRepeller( Repeller& repeller ) {
    for (int i = 0; i < particles.size(); i++ ) {
        Vec2f force = repeller.repel(*particles[i]);
        particles[i]->applyForce(force);
    }
}