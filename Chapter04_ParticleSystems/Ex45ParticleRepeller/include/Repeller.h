//
//  Repeller.h
//  Ex45ParticleRepeller
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/19/13
//

#ifndef __Ex45ParticleRepeller__Repeller__
#define __Ex45ParticleRepeller__Repeller__

#include "Math.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;

class Repeller {
    
public:
    Repeller( const Vec2f& location_ );
    
    void setLocation( const Vec2i& mouse );
    Vec2f repel( const Vec2f& particlePosition ) const;
    void draw() const;
    
private:
    Vec2f location;
    const float radius;
    const float strength;

};

#endif /* defined(__Ex45ParticleRepeller__Repeller__) */
