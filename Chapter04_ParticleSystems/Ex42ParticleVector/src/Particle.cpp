//
//  Particle.cpp
//  Ex42ParticleVector
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//  HWH Maintenance 8/17/13
//

#include "Particle.h"

Particle::Particle( const Vec2f& origin, Rand& r )
: position( origin ),
  lifespan( 1.0f ),
  velocity( r.nextFloat( -1.0f, 1.0f ), r.nextFloat( -1.0f, 1.0f ) ),
  acceleration( 0.0f, r.nextFloat( 0.01f, 0.03f ) ),
  aging( r.nextFloat( ( 1.0f / 64 ), ( 1.0f / 128 ) ) ),
  sizeRadius( r.nextFloat( 3.0f, 9.0f ) )
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