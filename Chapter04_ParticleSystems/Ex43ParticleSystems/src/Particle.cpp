//
//  Particle.cpp
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/19/13
//

#include "Particle.h"

Particle::Particle( const Vec2f& origin_, Rand& random_ )
: position( origin_ ),
  velocity( random_.nextFloat( -1.0f, 1.0f ), random_.nextFloat( -1.0f, 1.0f ) ),
  acceleration( 0.0f, random_.nextFloat( 0.01f, 0.03f ) ),
  lifespan( 1.0f ),
  aging( random_.nextFloat( (1.0f / 50), (1.0f / 100) ) ),
  sizeRadius( random_.nextFloat( 2.0f, 7.0f ) )
{ }

void Particle::update()
{
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
}

void Particle::draw() const
{
    gl::color( 1.0f, 1.0f, 1.0f, lifespan );
    gl::drawSolidCircle( position, sizeRadius );
}

bool Particle::isDead() const
{
    if( lifespan < 0.0f ) {
        return true;
    }
    return false;
}
