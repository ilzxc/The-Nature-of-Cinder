//
//  Confetti.cpp
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#include "Confetti.h"

Confetti::Confetti( const Vec2f& origin, Rand& random, const int type )
: Particle( origin, random )
{
    if( type == 0 ) {
        shape = new Square( Particle::getRadius(), random.nextFloat( 0.0f, 360.0f ), random.nextFloat( -7.5f, 7.5f ) );
    } else {
        shape = new Triangle( Particle::getRadius(), random.nextFloat( 0.0f, 360.0f ), random.nextFloat( -7.5f, 7.5f ) );
    }
}

Confetti::~Confetti()
{
    delete shape;
}

void Confetti::update()
{
    Particle::update();
    shape->update();
}

void Confetti::draw() const
{
    Particle::draw( *shape );
}

