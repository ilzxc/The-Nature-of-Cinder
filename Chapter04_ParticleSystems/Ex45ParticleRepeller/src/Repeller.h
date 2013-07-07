//
//  Repeller.h
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex45ParticleRepeller__Repeller__
#define __Ex45ParticleRepeller__Repeller__

#include "Math.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;

class Repeller {
private:
    Vec2f location;
    float radius;
    float strength;
    
public:
    Repeller() {}
    Repeller( Vec2f l )
    : location( l ),
      radius(50.0f),
      strength(30.0f) {
    }
    ~Repeller() {}
    void draw();
    Vec2f repel( const Particle& p ) const;
    bool clickedInside( Vec2i mouse );
    void setLocation( Vec2i mouse );
};

#endif /* defined(__Ex45ParticleRepeller__Repeller__) */
