//
//  RoundConfetti.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/7/13.
//
//

#include "RoundConfetti.h"

RoundConfetti::RoundConfetti( const Vec2f& origin, Rand& random )
: Particle( origin, random ),
  circle( new Circle( Particle::getRadius() ) )
{ }

RoundConfetti::~RoundConfetti()
{
    delete circle;
}

void RoundConfetti::draw() const
{
    Particle::draw( *circle );
}

