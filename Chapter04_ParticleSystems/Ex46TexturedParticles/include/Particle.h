//
//  Particle.h
//  Ex46TexturedParticles
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex46TexturedParticles__Particle__
#define __Ex46TexturedParticles__Particle__

#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
    
public:
    Particle( const gl::Texture* image, const Vec2f& origin, Rand& random );
    
    void update( const Vec2f& force);
    void draw() const;
    bool isDead() const;
    
private:
    const gl::Texture* texture; // pointer to a texture
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    const float aging;
    Rectf bounds;
    ColorAf color;

};

#endif /* defined(__Ex46TexturedParticles__Particle__) */
