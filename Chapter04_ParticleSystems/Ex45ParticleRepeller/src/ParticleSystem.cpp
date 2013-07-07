//
//  ParticleSystem.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "ParticleSystem.h"

void ParticleSystem::update( const Vec2f& force, Repeller& repeller, Rand& random ) {
    applyForce( force );
    applyRepeller( repeller );
    for(std::vector<Particle>::iterator iter = particles.begin(); iter != particles.end();) {
        iter->update();
        if ( iter->isDead() ) {
            iter = particles.erase(iter);
        } else {
            ++iter;
        }
    }
    addParticle( random );
    addParticle( random );
    
    // std::cout << "total number of particles present is " << particles.size() << std::endl;
}

void ParticleSystem::draw() {
    for( auto& i : particles) {
        i.draw();
    }
}

void ParticleSystem::addParticle( Rand& r ) {
    particles.push_back( Particle( origin, r ) );
}

void ParticleSystem::applyForce( const Vec2f& f ) {
    for (auto& i : particles) {
        i.applyForce(f);
    }
}

void ParticleSystem::applyRepeller( const Repeller& repeller ) {
    for (auto& i : particles) {
        Vec2f force = repeller.repel(i);
        i.applyForce(force);
    }
}