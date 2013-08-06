//
//  Particle.h
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 7/28/13.
//
//

#ifndef Ex58AdvancedCollisions_Particle_h
#define Ex58AdvancedCollisions_Particle_h

#include <Box2D/Box2D.h>
#include "Conversions.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Particle {
private:
    Vec2f position;
    float angle;
    float radius;
    Vec3f color;
    bool  isDead;
    
public:
    Particle( const Vec2f& _position, float _angle ): position( _position ), angle( _angle ), color( 0.0f, 0.0f, 0.0f ), isDead( false ) { }
    ~Particle() {}
    
    virtual void update( b2Body *body );
    virtual void draw() const;
    void startDraw() const;
    void endDraw() const;
    void setForDeletion();
    bool checkIfDead() const;
    void setColor( const float r, const float g, const float b );
};

#endif
