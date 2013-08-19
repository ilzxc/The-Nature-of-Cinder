//
//  Particle.cpp
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#include "Particle.h"

Particle::Particle( const Vec2f& origin, Rand& random )
: position( origin ),
  velocity( random.nextFloat( -1.0f, 1.0f ), random.nextFloat( -1.0f, 1.0f ) ),
  acceleration( Vec2f::zero() ),
  lifespan( 1.0f ),
  aging( random.nextFloat( ( 1.0f / 100 ), ( 1.0f / 200 ) ) ),
  sizeRadius( random.nextFloat( 2.0f, 7.0f ) ),
  rotation( random.nextFloat( 0.0f, 360.0f ) ),
  rotationSpeed( random.nextFloat( -5.0f, 5.0f ) ),
  bounds( -sizeRadius, -sizeRadius, sizeRadius, sizeRadius )
{
    sizeRadius /= 2.0f; // since the bounds are set, we update sizeRadius for drawing circles on our particles - see draw()
}

Vec2f Particle::getPosition() const
{
    return position;
}

void Particle::update()
{
    velocity += acceleration;
    position += velocity;
    lifespan -= aging;
    rotation += rotationSpeed;
}

void Particle::applyForce( const Vec2f& force )
{
    acceleration += force;
}

void Particle::draw() const
{
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( rotation );
    gl::color( 204.0f / 255, 33.0f / 255, 25.0 / 255, lifespan );
    gl::drawSolidRect( bounds );
    gl::color( 1.0f, 1.0f, 1.0f, lifespan );
    gl::drawSolidCircle( Vec2f::zero(), sizeRadius );
    gl::popMatrices();
}

bool Particle::isDead() const
{
    if( lifespan < 0.0f ) {
        return true;
    }
    return false;
}