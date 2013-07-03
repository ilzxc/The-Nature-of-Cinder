//
//  Particle.h
//  Ex46TexturedParticles
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex46TexturedParticles__Particle__
#define __Ex46TexturedParticles__Particle__

#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
private:
    const gl::Texture * texture; // pointer to a texture
    Vec2f position;
    Vec2f velocity;
    Vec2f acceleration;
    float lifespan;
    float aging;
    float sizeRadius;
    
public:
    Particle( const gl::Texture * image, const Vec2f origin, Rand& r ): texture(image), position(origin), lifespan(1.0) {
        velocity = Vec2f( r.nextGaussian() * 0.04f, r.nextGaussian() * 0.06f - 1.0f );
        acceleration = Vec2f( 0.0, 0.0 );
        aging = r.nextFloat( (1.0f / 200), (1.0f/ 300) );
        sizeRadius = r.nextFloat( 6, 11 );
    }
    ~Particle() {}
    void update( Vec2f& force);
    void draw();
    bool isDead();
};

#endif /* defined(__Ex46TexturedParticles__Particle__) */
