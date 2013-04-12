//
//  particle.h
//  ParticleGrids
//
//  Created by Ilya Rostovtsev on 4/11/13.
//
//

#ifndef ParticleGrids_particle_h
#define ParticleGrids_particle_h

#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/gl/gl.h"

class particle {
  public:
    ci::Vec2f   position;
    float       size;
    ci::Color   color;
    
    particle( ci::Vec2f setPosition, float setSize, ci::Color setColor );
    void update( const ci::Vec2f newPosition );
    void update( const float newSize );
    void update( const ci::Color newColor );
    void draw();
};

#endif
