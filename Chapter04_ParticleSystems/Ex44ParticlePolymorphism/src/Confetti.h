//
//  Confetti.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Confetti__
#define __Ex44ParticlePolymorphism__Confetti__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"
#include "Square.h"

using namespace ci;

class Confetti: public Particle {
private:
    Square square;
    float rotation;
    float rotationSpeed;

public:
    Confetti( const Vec2f origin, Rand& r )
    : Particle(origin, r),
      square( Particle::getRadius() ),
      rotation( r.nextFloat(0, 360) ),
      rotationSpeed( r.nextFloat(-5.0f, 5.0f) ) {
          Particle::setColor( Vec3f( 54.0f/255, 33.0f/255, 68.0f/255 ) );
    }
    ~Confetti() {}
    void update();
    void draw();
};

#endif /* defined(__Ex44ParticlePolymorphism__Confetti__) */
