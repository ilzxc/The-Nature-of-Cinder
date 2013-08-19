//
//  Particle.cpp
//  Ex46TexturedParticles
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#include "Particle.h"

Particle::Particle( const gl::Texture* image, const Vec2f& origin, Rand& random )
: texture( image ),
  position( origin ),
  velocity( random.nextGaussian() * 0.04f, random.nextGaussian() * 0.06f - 1.0f ),
  acceleration( Vec2f::zero() ),
  lifespan( 1.0f ),
  aging( random.nextFloat( 1.0f / 200, 1.0f / 300 ) ),
  color()
{
    float size = random.nextFloat( 6.0f, 11.0f );
    bounds = Rectf( -size, -size, size, size );
}

void Particle::update( const Vec2f& force )
{
    acceleration += force;
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
    color.set( 0.0f, lifespan * lifespan / 5.0f, lifespan * lifespan * lifespan, lifespan );
}

void Particle::draw() const
{
    gl::color( color );
    gl::pushMatrices();
    gl::translate(position);
    gl::draw( *texture, bounds );
    gl::popMatrices();
}

bool Particle::isDead() const
{
    if( lifespan < 0.0f ) {
        return true;
    }
    return false;
}