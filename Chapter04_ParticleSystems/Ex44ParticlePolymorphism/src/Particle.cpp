//
//  Particle.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "Particle.h"

Particle::Particle( const Vec2f& origin, Rand& random )
: position( origin ),
  velocity( random.nextFloat( -1.0f, 1.0f ), random.nextFloat( -1.0f, 1.0f ) ),
  acceleration( 0.0f, random.nextFloat( 0.01f, 0.03f ) ),
  lifespan( 1.0f ),
  aging( random.nextFloat( ( 1.0f / 100 ), ( 1.0f / 200 ) ) ),
  sizeRadius( random.nextFloat( 2.0f, 7.0f ) )
{ }

void Particle::update()
{
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
}

void Particle::draw( const Shape& shape ) const
{
    gl::pushMatrices();
    gl::translate( position );
    gl::color( shape.color.x, shape.color.y, shape.color.z, lifespan );
    shape.draw();
    gl::popMatrices();
}

bool Particle::isDead() const
{
    if( lifespan < 0.0f ) {
        return true;
    }
    return false;
}

float Particle::getRadius() const
{
    return sizeRadius;
}

float Particle::getLifespan() const
{
    return lifespan;
}
