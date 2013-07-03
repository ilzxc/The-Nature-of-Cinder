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
    Particle( const Vec2f origin, Rand& r ): position(origin), lifespan(1.0) {
        velocity = Vec2f( r.nextFloat( -1.0, 1.0 ), r.nextFloat( -1.0, 1.0 ) );
        acceleration = Vec2f( 0.0f, 0.0f );
        aging = r.nextFloat( (1.0f / 100), (1.0f/ 200) );
        sizeRadius = r.nextFloat( 2, 7 );
        rotation = r.nextFloat(0, 360);
        rotationSpeed = r.nextFloat(-5, 5);
    }
    ~Particle() {}
    const Vec2f getPosition();
    void update();
    void applyForce( const Vec2f& force );
    void draw();
    bool isDead();
};

#endif /* defined(__Ex45ParticleRepeller__Particle__) */
