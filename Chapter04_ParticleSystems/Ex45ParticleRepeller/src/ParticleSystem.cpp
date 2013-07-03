//
//  ParticleSystem.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "ParticleSystem.h"

ParticleSystem::~ParticleSystem() {
    for(auto i : particles) {
        delete i;
    }
}

void ParticleSystem::update( const Vec2f& force, Repeller * repeller, Rand& random ) {
    applyForce( force );
    applyRepeller( *repeller );
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
    for( auto i : particles) {
        i->draw();
    }
}

void ParticleSystem::addParticle( Rand& r ) {
    particles.push_back( new Particle( origin, r ) );
}

void ParticleSystem::applyForce( const Vec2f& f ) {
    for (auto i : particles) {
        i->applyForce(f);
    }
}

void ParticleSystem::applyRepeller( Repeller& repeller ) {
    for (auto i : particles) {
        Vec2f force = repeller.repel(*i);
        i->applyForce(force);
    }
}