//
//  Particle.h
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex45ParticleRepeller__Particle__
#define __Ex45ParticleRepeller__Particle__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
    
public:
    Particle( const Vec2f& origin, Rand& random );
    
    Vec2f getPosition() const;
    void update();
    void applyForce( const Vec2f& force );
    void draw() const;
    bool isDead() const;
    
protected:
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    const float aging;
    float sizeRadius;
    float rotation;
    const float rotationSpeed;
    Rectf bounds;
    
};

#endif /* defined(__Ex45ParticleRepeller__Particle__) */
