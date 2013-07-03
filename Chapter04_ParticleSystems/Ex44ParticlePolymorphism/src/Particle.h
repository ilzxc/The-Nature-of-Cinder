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
    Vec3f color;
    
public:
    Particle( const Vec2f origin, Rand& r ){
        position = origin;
        velocity = Vec2f( r.nextFloat( -1.0, 1.0 ), r.nextFloat( -1.0, 1.0 ) );
        acceleration = Vec2f( 0.0, r.nextFloat( 0.01, 0.03 ) );
        lifespan = 1.0f;
        aging = r.nextFloat( (1.0f / 100), (1.0f/ 200) );
        sizeRadius = r.nextFloat( 2, 7 );
        rotation = r.nextFloat(0, 360);
        color = Vec3f(154.0/255, 40.0/255, 47.0/255);
    }
    virtual ~Particle() {}
    
    virtual void update();
    virtual void draw();
    bool isDead();
    void setColor(Vec3f newColor);
    
};

#endif /* defined(__Ex44ParticlePolymorphism__Particle__) */
