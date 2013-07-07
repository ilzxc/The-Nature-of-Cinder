//
//  ParticleSystem.h
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex45ParticleRepeller__ParticleSystem__
#define __Ex45ParticleRepeller__ParticleSystem__

#include "cinder/Rand.h"
#include "Particle.h"
#include "Repeller.h"
#include <vector>

using namespace ci;

class ParticleSystem {
    
private:
    std::vector<Particle> particles;
    Vec2f origin;
    
    void addParticle( Rand& r );
    void applyForce( const Vec2f& f );
    void applyRepeller( const Repeller& repeller );
    
    
public:
    ParticleSystem() {}
    ParticleSystem( const Vec2f& o, Rand& r ): origin(o) {
        addParticle( r );
    }
    ~ParticleSystem() {}
        
    void update( const Vec2f& force, Repeller& repeller, Rand& random );
    void draw();
};

#endif /* defined(__Ex45ParticleRepeller__ParticleSystem__) */
