//
//  ParticleSystem.h
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex45ParticleRepeller__ParticleSystem__
#define __Ex45ParticleRepeller__ParticleSystem__

#include "cinder/Rand.h"
#include "Particle.h"
#include "Repeller.h"
#include <vector>

using namespace ci;

class ParticleSystem {
    
public:
    ParticleSystem( const Vec2f& origin_ );
    ~ParticleSystem();
    
    void update( const Vec2f& gravity, Repeller& repeller, Rand& random );
    void draw() const;
    
private:
    void addParticle( Rand& random );
    
    std::vector< std::unique_ptr< Particle > > particles;
    Vec2f origin;
    
};

#endif /* defined(__Ex45ParticleRepeller__ParticleSystem__) */
