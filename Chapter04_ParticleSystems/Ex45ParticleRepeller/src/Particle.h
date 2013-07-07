//
//  Particle.h
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex45ParticleRepeller__Particle__
#define __Ex45ParticleRepeller__Particle__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
protected:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    float aging;
    float sizeRadius;
    float rotation;
    float rotationSpeed;
    
public:
    Particle( const Vec2f& origin, Rand& r )
    : position(origin),
      velocity( r.nextFloat( -1.0f, 1.0f ), r.nextFloat( -1.0f, 1.0f ) ),
      acceleration( Vec2f::zero() ),
      lifespan(1.0f),
      aging( r.nextFloat( (1.0f / 100), (1.0f/ 200) ) ),
      sizeRadius( r.nextFloat( 2.0f, 7.0f ) ),
      rotation( r.nextFloat(0.0f, 360.0f) ),
      rotationSpeed( r.nextFloat(-5.0f, 5.0f) ) {
    }
    ~Particle() {}
    Vec2f getPosition() const;
    void update();
    void applyForce( const Vec2f& force );
    void draw();
    bool isDead();
};

#endif /* defined(__Ex45ParticleRepeller__Particle__) */
