//
//  Particle.h
//  Ex43ParticleSystems
//
//  Created by Ilya Rostovtsev on 7/2/13.
//
//

#ifndef __Ex43ParticleSystems__Particle__
#define __Ex43ParticleSystems__Particle__

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

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
    Particle( const Vec2f origin, Rand& r ): position(origin), velocity( r.nextFloat( -1.0f, 1.0f ), r.nextFloat( -1.0f, 1.0f ) ) , acceleration( 0.0f, r.nextFloat( 0.01f, 0.03f ) ), lifespan(1.0f), aging( r.nextFloat( (1.0f / 50), (1.0f/ 100) ) ), sizeRadius( r.nextFloat( 2, 7 ) ) { }
    ~Particle() {}
    void update();
    void draw();
    bool isDead();
};

#endif /* defined(__Ex43ParticleSystems__Particle__) */
