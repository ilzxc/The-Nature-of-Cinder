//
//  Particle.h
//  Ex44ParticlePolymorphism
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#ifndef __Ex44ParticlePolymorphism__Particle__
#define __Ex44ParticlePolymorphism__Particle__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Square.h"

using namespace ci;

class Particle {
private:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    float aging;
    float sizeRadius;
    
public:
    Particle( const Vec2f origin, Rand& r )
    : position(origin),
      velocity( r.nextFloat( -1.0f, 1.0f ), r.nextFloat( -1.0f, 1.0f ) ),
      acceleration( 0.0f, r.nextFloat( 0.01f, 0.03f ) ),
      lifespan( 1.0f ),
      aging( r.nextFloat( (1.0f / 100), (1.0f/ 200) ) ),
      sizeRadius( r.nextFloat( 2.0f, 7.0f ) ) {
    }
    virtual ~Particle() {}
    
    virtual void update();
    virtual void draw() = 0;
    void draw( const Shape& shape ) const;
    bool isDead();
    float getRadius() const;
    float getLifespan() const;
    
};

#endif /* defined(__Ex44ParticlePolymorphism__Particle__) */
